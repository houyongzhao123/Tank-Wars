#include "EnemyLayer.h"
#include "OneTank.h"
#include "TwoTank.h"
#include "ThreeTank.h"
#include "MapLayer.h"
#include "GameScene.h"
#include "EnemyManager.h"
bool EnemyLayer::init(){
	if(!Layer::init()){
		return false;
	}
	//每25秒出一波坦克
	this->schedule(schedule_selector(EnemyLayer::update),5);
	return true;
}
void EnemyLayer::Outtank(){
	GameScene * scene =dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	MapLayer* maps = dynamic_cast<MapLayer*>(scene->getMaplayer());
	//当场上坦克个数多余5个就停止出坦克最多场上有8个坦克
	int n = EnemyManager::getInstance()->getEnemyManger().size();
	if(n<=5){
	TwoTank::create(maps->getState(0));
	OneTank::create(maps->getState(1));
	ThreeTank::create(maps->getState(2));
	}else{
		return;
	}
}
void EnemyLayer:: onEnter(){
	Layer::onEnter();
		this->Outtank();
}
void EnemyLayer::update(float t){
	this->onEnter();
}