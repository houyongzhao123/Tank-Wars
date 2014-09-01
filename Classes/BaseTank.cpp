#include "BaseTank.h"
#include "Basebullet.h"
bool BaseTank::initWithSpriteFrameName(std::string name,int hp,int speed){
	if(!Sprite::initWithSpriteFrameName(name)){
		return false;
	}
	this->setisStop(true);
	this->runAnimate();
	this->hp=hp;
	this->speed=speed;
	this->state=Up;
	this->isdie=false;
	this->schedule(schedule_selector(BaseTank::move));
	return true;
}
void BaseTank::move(float t){
	this->setRotation(state*90);
	if (isstop)
	{
		return;
	}
	if(state==Up){
		
		this->setPositionY(this->getPositionY()+speed * t);
	}else if(state==Down){
		this->setPositionY(this->getPositionY()-speed * t);
	}else if(state==Left){
		this->setPositionX(this->getPositionX()-speed * t);
	}else if(state==Right){
		this->setPositionX(this->getPositionX()+speed * t);
	}
}
void BaseTank::hurt(int hp){
	this->hp-=hp;
	if(this->hp<=0){
		this->isdie=true;
		this->removeFromParentAndCleanup(true);
		log("%d",this->hp);
	}
	
}
Vec2& BaseTank::getNextFramePostion()
{   
	float fps = Director::getInstance()->getAnimationInterval();
	auto point = this->getPosition();
	if(state==Up){
		point.y =this->getPositionY()+speed*fps;
	}else if(state==Down){
		point.y = this->getPositionY()-speed*fps;
	}else if(state==Left){
		point.x = this->getPositionX()-speed*fps;
	}else if(state==Right){
		point.x = this->getPositionX()+speed*fps;
	}
	return point;
}
Rect& BaseTank::getNextFrameBoundingBox()
{   
	auto point = getNextFramePostion();
	auto height = this->getContentSize().height;
	auto width = this->getContentSize().width;
	float x = point.x - width/2;
	float y = point.y - height/2;
	return Rect(x,y,width,height);
}