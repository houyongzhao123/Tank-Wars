#include "LogicLayer.h"
#include "MapLayer.h"
#include "GameScene.h"
#include "EnemyManager.h"
#include "BulletManager.h"
bool LogicLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
    auto sprite = Sprite::createWithSpriteFrameName("en1.png");
	sprite->setPosition(Vec2(800,400));
	sprite->setTag(1);
	this->addChild(sprite);

	//
    enemycount=20;
	enemystr = StringUtils::format("x %d",enemycount);
	enemylable = Label::createWithSystemFont(enemystr,"Airal",20);
	score=0;
	enemylable->setPosition(850,400);
	this->addChild(enemylable);
	scorestr = StringUtils::format("score:%d",score);
	scorelable = Label::createWithSystemFont(scorestr,"Arial",20);
	scorelable->setPosition(Vec2(850,500));
	this->addChild(scorelable);

	this->scheduleUpdate();

	auto center = __NotificationCenter::getInstance();
	center->addObserver(this,callfuncO_selector(LogicLayer::reciveEnemyDie),"EnemyDie",nullptr);//注册敌军死亡通知 
	return true;
}
void LogicLayer::TankTestBound()
{  
	auto scene =dynamic_cast<GameScene *> (Director::getInstance()->getRunningScene());
	auto tank = (BaseTank*)scene->getTanklayer()->getChildByName("tank");
	if (tank == nullptr)
	{
		return;
	}//判定Tank是否为空

	Vector<BaseTank *> vc = EnemyManager::getInstance()->getEnemyManger();
	for (auto iter = vc.begin();iter!=vc.end();iter++)
	{
		auto enemy = *iter;
		if (tank->getNextFrameBoundingBox().intersectsRect(enemy->getBoundingBox()))
		{
			tank->setisStop(true);
		}
	}

}
void LogicLayer::BulletTestBound()
{
	bulletEvsT();
	bulletvsBarrer();
	bulletVsTank();
	bulletVsEnemy();
}
void LogicLayer::bulletEvsT()
{   //敌军子弹和己方子弹的碰撞
	auto enemybu = BulletManager::getInstance()->getEnemyBulletManger();
	auto tankbu = BulletManager::getInstance()->getTankBulletManager();
	for (auto eiter = enemybu.begin();eiter!=enemybu.end();eiter++)
	{   auto enemybullet = *eiter;
		for (auto titer = tankbu.begin();titer!=tankbu.end();titer++)
		{   auto tankbullet = *titer;
			if (enemybullet->getBoundingBox().intersectsRect(tankbullet->getBoundingBox()))
			{
				//设置所有子弹消失状态
				tankbullet->remove();
				enemybullet->remove();
			}
		}
	}
}
void LogicLayer::bulletvsBarrer()
{   
	auto scene = dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	auto map = dynamic_cast<MapLayer *>(scene->getChildByName("map"));
	/*auto sp = this->getChildByTag(1);
	auto t = map->checkIsNode(sp->getPosition());
	log("%d",t);*/
	//子弹和障碍
	auto tankbu = BulletManager::getInstance()->getTankBulletManager();
	auto enemybu = BulletManager::getInstance()->getEnemyBulletManger();
	for (auto titer = tankbu.begin();titer!=tankbu.end();titer++)
	{    auto bu = (*titer);
		if (map->checkIsNode(bu->getPosition()))
		{
			if (map->checkNodeBreak(bu->getPosition()))
			{
				map->breakNode(bu->getPosition());	
			}
			bu->remove();
		}
	}
	for (auto titer = enemybu.begin();titer!=enemybu.end();titer++)
	{    auto bu = (*titer);
	if (map->checkIsNode(bu->getPosition()))
	{
		if (map->checkNodeBreak(bu->getPosition()))
		{
			map->breakNode(bu->getPosition());
			
		}
		bu->remove();
	}
	}
}

void LogicLayer::bulletVsEnemy()
{
	auto tankbu = BulletManager::getInstance()->getTankBulletManager();
	auto enemy = EnemyManager::getInstance()->getEnemyManger();
	for(auto titer = tankbu.begin();titer!=tankbu.end();titer++)
	{  auto tankbullet = *titer;
	   for (auto eiter = enemy.begin();eiter!=enemy.end();eiter++)
	   {   
		   auto enemy = *eiter;
		   if (enemy->getBoundingBox().intersectsRect(tankbullet->getBoundingBox()))
		   {
			   //设置消失状态
			   tankbullet->remove();
			   enemy->hurt(tankbullet->getATTACK());
		   }
	   }
	}
}
void LogicLayer::bulletVsTank()
{
	auto enemybu = BulletManager::getInstance()->getEnemyBulletManger();
	auto scene =dynamic_cast<GameScene *> (Director::getInstance()->getRunningScene());
	auto tank =(BaseTank *) scene->getTanklayer()->getChildByName("tank");
	
	if (tank==nullptr)
	{
		return;
	}
	tank->retain();
	for (auto eiter = enemybu.begin();eiter!=enemybu.end();eiter++)
	{   auto bullet = *eiter;
		if (tank->getBoundingBox().intersectsRect(bullet->getBoundingBox()))
		{
			//tank掉血 gameover
			tank->hurt(bullet->getATTACK());
			bullet->remove();

		}
	}
	tank->release();
}
void LogicLayer::update(float t)
{   //清理失效物件
	TankTestBound();
	BulletTestBound();
	BulletManager::getInstance()->removeAllBullets();
	EnemyManager::getInstance()->removeAllenemys();
}
void LogicLayer::reciveEnemyDie(Ref * obj)
{
	enemycount--;
	enemystr = StringUtils::format("x %d",enemycount);
	enemylable->setString(enemystr);
	score = score+10;
	scorestr = StringUtils::format("score:%d",score);
	scorelable->setString(scorestr);
	this->addChild(scorelable);
	//分数改变
}