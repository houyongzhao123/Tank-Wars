#include "GameScene.h"
#include "MapLayer.h"
#include "Tanklayer.h"
#include "EnemyLayer.h"
#include "LogicLayer.h"
bool GameScene::init(){
	if(!Scene::init()){
		return false;
	}
	//加入帧缓存图片
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image.plist");
	//加入地图层
	auto maplayer= MapLayer::create();
	maplayer->setName("map");
	this->addChild(maplayer);
	//加入主坦克层
	auto tanklyer = Tanklayer::create();
	tanklyer->setName("tanklyer");
	this->addChild(tanklyer);
	//加入敌方坦克
	auto enemylayer = EnemyLayer::create();
	enemylayer->setName("enemlayer");
	this->addChild(enemylayer);
	//逻辑
    auto logiclayer = LogicLayer::create();
	this->addChild(logiclayer);
	return true;
}
Layer* GameScene::getTanklayer(){
	return this-> getChildByName<Layer*>("tanklyer");	
}
Layer* GameScene::getMaplayer(){
	return this-> getChildByName<Layer*>("map");
}
Layer* GameScene::getenemlayer(){
	return this-> getChildByName<Layer*>("enemlayer");	
}