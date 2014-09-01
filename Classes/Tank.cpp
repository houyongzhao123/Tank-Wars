#include "Tank.h"
#include "Basebullet.h"
#include "BulletManager.h"
Tank* Tank::create(){
	Tank *mytank =new Tank();
	if(mytank && mytank->init())
	{
		mytank->autorelease();
		return mytank;
	}
	CC_SAFE_DELETE(mytank);
	return nullptr;
}
bool Tank::init(){
	if(!BaseTank::initWithSpriteFrameName("p1.png",TANKHP,SPEED))
	{
		return false;
	}

	return true;
}
void Tank::addBulletToManager(Basebullet * bullet)
{
	BulletManager::getInstance()->addTankBullet(bullet);
}
void Tank::runAnimate()
{
	auto animt =Animation::create();
	auto cache =SpriteFrameCache::getInstance();
	animt->addSpriteFrame(cache->getSpriteFrameByName("p1-a.png"));
	animt->addSpriteFrame(cache->getSpriteFrameByName("p1-b.png"));
	animt->addSpriteFrame(cache->getSpriteFrameByName("p1-c.png"));
	animt->setDelayPerUnit(0.1f);
	animt->setLoops(-1);
	this->runAction(Animate::create(animt));
}
//2014-9-1 17:13:57ÒÆ³ıfire,Ôö¼ÓaddaddBulletToManager