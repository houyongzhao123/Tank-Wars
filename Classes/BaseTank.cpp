#include "BaseTank.h"
#include "Basebullet.h"
#include "GameScene.h"
#include "MapLayer.h"

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
// 	auto scene=dynamic_cast<GameScene*>(Director::getInstance()->getRunningScene());
// 	auto layer=dynamic_cast<MapLayer*>(scene->getMaplayer());

	this->setRotation(state*90);
	if (isstop)
	{
		return;
	}
	if(state==Up){
		if (boundingBox(Vec2(this->getPositionX(),this->getPositionY()+speed * t+8))||(this->getPositionY()+this->getContentSize().height/2>640))
		{
			return;
		}
		this->setPositionY(this->getPositionY()+speed * t);
	}else if(state==Down){
		if (boundingBox(Vec2(this->getPositionX(),this->getPositionY()-speed * t-8))||(this->getPositionY()-this->getContentSize().height/2<0))
		{
			return;
		}
		this->setPositionY(this->getPositionY()-speed * t);
	}else if(state==Left){
		if (boundingBox(Vec2(this->getPositionX()-speed * t -8,this->getPositionY()))||(this->getPositionX()-this->getContentSize().width/2<0))
		{
			return;
		}
		this->setPositionX(this->getPositionX()-speed * t);
	}else if(state==Right){
		if (boundingBox(Vec2(this->getPositionX()+speed * t +8,this->getPositionY()))||(this->getPositionX()+this->getContentSize().width/2>640))
		{
			return;
		}
		this->setPositionX(this->getPositionX()+speed * t);
	}
}

bool BaseTank::boundingBox(Vec2 position)//移动后碰撞检测
{
	auto scene = dynamic_cast<GameScene*>(Director::getInstance()->getRunningScene());
	auto layer = dynamic_cast<MapLayer*>(scene->getMaplayer());
	auto point1 = Vec2(position.x - 11, position.y - 11);
	auto point2 = Vec2(position.x - 11, position.y + 11);
	auto point3 = Vec2(position.x + 11, position.y + 11);
	auto point4 = Vec2(position.x + 11, position.y - 11);
	if (!layer->checkIsNode(point1) && !layer->checkIsNode(point2) && !layer->checkIsNode(point3) && !layer->checkIsNode(point4)){
		return false;
	}
	return true;
}
void BaseTank::hurt(int hp){
	auto center = __NotificationCenter::getInstance();
	
	this->hp-=hp;
	center->postNotification("TankHurt",this);
	if(this->hp<=0){
		this->isdie=true;
		
		center->postNotification("EnemyDie",this);
		
		this->removeFromParentAndCleanup(true);
		log("%d",this->hp);
	}
	
}
Vec2& BaseTank::getNextFramePostion()//获取下一帧的坐标
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
Rect& BaseTank::getNextFrameBoundingBox()//获取下一帧碰撞矩形
{   
	auto point = getNextFramePostion();
	auto height = this->getContentSize().height;
	auto width = this->getContentSize().width;
	float x = point.x - width/2;
	float y = point.y - height/2;
	return Rect(x,y,width,height);
}