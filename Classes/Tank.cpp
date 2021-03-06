#include "Tank.h"
#include "Basebullet.h"
#include "BulletManager.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
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
void Tank::fire(){
	SimpleAudioEngine::getInstance()->playEffect("bullet.aif");
	auto bullet = Basebullet::Createbullet(this->getPosition(),this->getState());
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
void Tank::playMoveEffect()
{
	SimpleAudioEngine::getInstance()->playEffect("move.aif");
}