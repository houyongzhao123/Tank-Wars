#include "EnemyLayer.h"
#include "OneTank.h"
#include "TwoTank.h"
#include "MapLayer.h"
#include "GameScene.h"
bool EnemyLayer::init(){
	if(!Layer::init()){
		return false;
	}

	return true;
}
void EnemyLayer::Outtank(){
	GameScene * scene =dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	MapLayer* maps = dynamic_cast<MapLayer*>(scene->getMaplayer());
	OneTank::create(maps->getState(0));
	TwoTank::create(maps->getState(1));
}
void EnemyLayer:: onEnter(){
	Layer::onEnter();
		this->Outtank();
}