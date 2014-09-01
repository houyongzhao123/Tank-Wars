#include "BaseTank.h"
#include "Basebullet.h"
bool BaseTank::initWithSpriteFrameName(std::string name,int hp,int speed){
	if(!Sprite::initWithSpriteFrameName(name)){
		return false;
	}
	this->setisStop(false);
	this->runAnimate();
	this->hp=hp;
	this->speed=speed;
	this->state=Up;
	this->isdie=false;
	return true;
}
void BaseTank::move(moverect State){
	this->state = State;
	this->setRotation(state*90);
	if (isstop)
	{
		return;
	}
	if(State==Up){
		
		this->setPositionY(this->getPositionY()+speed);
	}else if(State==Down){
		this->setPositionY(this->getPositionY()-speed);
	}else if(State==Left){
		this->setPositionX(this->getPositionX()-speed);
	}else if(State==Right){
		this->setPositionX(this->getPositionX()+speed);
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
	auto point = this->getPosition();
	if(state==Up){
		point.y =this->getPositionY()+speed;
	}else if(state==Down){
		point.y = this->getPositionY()-speed;
	}else if(state==Left){
		point.x = this->getPositionX()-speed;
	}else if(state==Right){
		point.x = this->getPositionX()+speed;
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