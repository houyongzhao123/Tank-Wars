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


	auto leister = EventListenerTouchOneByOne::create();
	leister->onTouchBegan = [=](Touch *t,Event *e){sprite->setPosition(t->getLocation());return true;};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(leister,this);
	this->scheduleUpdate();
	return true;
}
void LogicLayer::TankTestBound()
{
	auto scene =dynamic_cast<GameScene *> (Director::getInstance()->getRunningScene());
	auto tank = scene->getTanklayer()->getChildByName("tank");
	Vector<BaseTank *> vc = EnemyManager::getInstance()->getEnemyManger();
	for (auto iter = vc.begin();iter!=vc.end();iter++)
	{
		auto enemy = *iter;
		if (tank->getBoundingBox().intersectsRect(enemy->getBoundingBox()))
		{
			tank->setPosition(tank->getPosition());
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
			}
		}
	}
}
void LogicLayer::bulletvsBarrer()
{   
	/*auto scene = dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	auto map = dynamic_cast<MapLayer *>(scene->getChildByName("map"));
	auto sp = this->getChildByTag(1);
	auto t = map->checkIsNode(sp->getPosition());
	log("%d",t);*/
	//子弹和障碍
	/*for (ene)
	{
	}*/
}

void LogicLayer::bulletVsEnemy()
{
	auto tankbu = BulletManager::getInstance()->getTankBulletManager();
	auto enemy = EnemyManager::getInstance()->getEnemyManger();
	for(auto titer = tankbu.begin();titer!=tankbu.end();titer++)
	{  auto tankbullet = *titer;
	   for (auto eiter = enemy.begin();eiter!=enemy.end();titer++)
	   {   
		   auto enemybullet = *eiter;
		   if (enemybullet->getBoundingBox().intersectsRect(tankbullet->getBoundingBox()))
		   {
			   //设置消失状态
		   }
	   }
	}
}
void LogicLayer::bulletVsTank()
{
	auto enemybu = BulletManager::getInstance()->getEnemyBulletManger();
	auto scene =dynamic_cast<GameScene *> (Director::getInstance()->getRunningScene());
	auto tank = scene->getTanklayer()->getChildByName("tank");
	for (auto eiter = enemybu.begin();eiter!=enemybu.end();eiter++)
	{   auto bullet = *eiter;
		if (tank->getBoundingBox().intersectsRect(bullet->getBoundingBox()))
		{
			//tank掉血 gameover
		}
	}
}
void LogicLayer::update(float t)
{
	TankTestBound();
	BulletTestBound();
}