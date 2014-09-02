#include "LogicLayer.h"
#include "MapLayer.h"
#include "GameScene.h"
#include "EnemyManager.h"
#include "BulletManager.h"
#include "GameOverLayer.h"
bool LogicLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
   
	//̹��HP
	this->scheduleUpdate();
	//��ͣ����
	 Label *l =Label::createWithBMFont("fonts/futura-48.fnt","Pause/Resume");
	 l->setPosition(Vec2(850,610));
	 l->setScale(0.2f);
	auto sp1 =Sprite::create("stop1.png");
	auto sp2 =Sprite::create("stop2.png");
	auto item =MenuItemSprite::create(sp1,sp2,[=](Ref *){
		if(Director::getInstance()->isPaused())
		{
        Director::getInstance()->resume();
        }
		else
		{
			Director::getInstance()->pause();
		}
	});
	auto menu =Menu::create(item,NULL);
	menu->setPosition(Vec2(610,400));
	menu->setScale(0.5f);
	this->addChild(menu);
	this->addChild(l);
	return true;
}
void LogicLayer::TankTestBound()
{  //̹�˼���ײ
	auto scene =dynamic_cast<GameScene *> (Director::getInstance()->getRunningScene());
	auto tank = (BaseTank*)scene->getTanklayer()->getChildByName("tank");
	if (tank == nullptr)
	{
		return;
	}//�ж�Tank�Ƿ�Ϊ��

	Vector<BaseTank *> vc = EnemyManager::getInstance()->getEnemyManger();
	for (auto iter = vc.begin();iter!=vc.end();iter++)
	{
		auto enemy = *iter;
		if (tank->getNextFrameBoundingBox().intersectsRect(enemy->getBoundingBox()))
		{
			tank->setisStop(true);
		}
		if (enemy->getNextFrameBoundingBox().intersectsRect(tank->getBoundingBox()))
		{
			enemy->setisStop(true);
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
{   //�о��ӵ��ͼ����ӵ�����ײ
	auto enemybu = BulletManager::getInstance()->getEnemyBulletManger();
	auto tankbu = BulletManager::getInstance()->getTankBulletManager();
	for (auto eiter = enemybu.begin();eiter!=enemybu.end();eiter++)
	{   auto enemybullet = *eiter;
		for (auto titer = tankbu.begin();titer!=tankbu.end();titer++)
		{   auto tankbullet = *titer;
			if (enemybullet->getBoundingBox().intersectsRect(tankbullet->getBoundingBox()))
			{
				//���������ӵ���ʧ״̬
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
	//�ӵ����ϰ�
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
		   if (enemy->getBoundingBox().intersectsRect(tankbullet->getBoundingBox())&&!enemy->getISdie())
		   {
			   //������ʧ״̬
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
			//tank��Ѫ gameover
			tank->hurt(bullet->getATTACK());
			bullet->remove();
			
		}
	}
	tank->release();
}
void LogicLayer::update(float t)
{   //����ʧЧ���
	TankTestBound();
	BulletTestBound();
	checkisDefeated();
	BulletManager::getInstance()->removeAllBullets();
	EnemyManager::getInstance()->removeAllenemys();
}
void LogicLayer::checkisDefeated()
{  
	auto scene = dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	auto map = dynamic_cast<MapLayer *>(scene->getChildByName("map"));
	auto tank = (BaseTank*)scene->getTanklayer()->getChildByName("tank");
	if (map->isDefeated()||tank==nullptr)
	{
		map->failed();
		this->addChild(GameOverLayer::create());
		this->unscheduleAllSelectors();		
	}
}