#include "BaseTank.h"
#include "Basebullet.h"
bool BaseTank::initWithSpriteFrameName(std::string name,int hp,int speed){
	if(!Sprite::initWithSpriteFrameName(name)){
		return false;
	}
	this->runAnimate();
	this->hp=hp;
	this->speed=speed;
	this->state=Up;
	return true;
}
void BaseTank::move(moverect State){
	if(State==Up){
		this->setRotation(0);
		this->setPositionY(this->getPositionY()+speed);
	}else if(State==Down){
		this->setRotation(180);
		this->setPositionY(this->getPositionY()-speed);
	}else if(State==Left){
		this->setRotation(270);
		this->setPositionX(this->getPositionX()-speed);
	}else if(State==Right){
		this->setRotation(90);
		this->setPositionX(this->getPositionX()+speed);
	}
}