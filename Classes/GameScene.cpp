#include "GameScene.h"
#include "Tanklayer.h"
#include "Maplayer.h"
#include "LogicLayer.h"
bool GameScene::init(){
	if(!Scene::init()){
		return false;
	}
	//����֡����ͼƬ
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image.plist");
	//�����ͼ��

	auto map = MapLayer::create();
	map->setName("map");
	//������̹�˲�
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