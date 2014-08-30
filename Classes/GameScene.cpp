#include "GameScene.h"
#include "Tanklayer.h"
#include "Maplayer.h"
#include "LogicLayer.h"
bool GameScene::init(){
	if(!Scene::init()){
		return false;
	}
	//加入帧缓存图片
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image.plist");
	//加入地图层

	auto map = MapLayer::create();
	map->setName("map");
	//加入主坦克层
	auto tanklyer = Tanklayer::create();
	tanklyer->setName("tanklyer");
	auto logiclayer = LogicLayer::create();
	this->addChild(logiclayer,100);
	this->addChild(map);
	this->addChild(tanklyer);
    
	return true;
}
Layer* GameScene::getTanklayer(){
	return this-> getChildByName<Tanklayer*>("tanklyer");	
}
Layer*GameScene::getMapLayer(){
	return this->getChildByName<Layer*>("map");
}