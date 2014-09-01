#include "EnemyLayer.h"
#include "OneTank.h"
#include "TwoTank.h"
#include "ThreeTank.h"
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
	TwoTank::create(Vec2(400,220));

	ThreeTank::create(maps->getState(2));
}
void EnemyLayer:: onEnter(){
	Layer::onEnter();
		this->Outtank();
}