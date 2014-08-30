#include "Basebullet.h"
#include "GameScene.h"
Basebullet* Basebullet::Createbullet(Vec2 position,moverect STATE){
	Basebullet *bullet =new Basebullet();
	if(bullet && bullet->initWithTank(position,STATE))
	{
		bullet->autorelease();
		return bullet;
	}
	CC_SAFE_DELETE(bullet);
	return nullptr;
}
bool Basebullet::initWithTank(Vec2 position,moverect STATE){
	if(!Sprite::initWithSpriteFrameName("bullet.png")){
		return false;
	}
	this->STATE = STATE;
	this->position=position;
	this->setPosition(position);
	vsize = Director::getInstance()->getVisibleSize();
	
	GameScene * scene =dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	//通过游戏场景得到游戏层并把子弹贴在游戏层
	scene->getTanklayer()->addChild(this);
	this->move();
	return true;
}
void Basebullet::move(){
	if(STATE==0){
		this->runAction(MoveBy::create(((vsize.height-this->getPositionY())/YIDONGSUDU),Vec2(0,(vsize.height-this->getPositionY()))));
	}else if(STATE==1){
		this->runAction(MoveBy::create((this->getPositionY()/YIDONGSUDU),Vec2(0,0-this->getPositionY())));
	}else if(STATE==2){
		this->runAction(MoveBy::create((this->getPositionX()/YIDONGSUDU),Vec2(0-this->getPositionX(),0)));
	}else if(STATE==3){
		this->runAction(MoveBy::create((vsize.width/YIDONGSUDU),Vec2(vsize.width-this->getPositionX(),0)));
	}
}