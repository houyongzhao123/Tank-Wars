#include "GameScene.h"
#include "MapLayer.h"
#include "Tanklayer.h"
#include "EnemyLayer.h"
#include "LogicLayer.h"
bool GameScene::init(){
	if(!Scene::init()){
		return false;
	}
	//����֡����ͼƬ
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image.plist");
	//�����ͼ��
	auto maplayer= MapLayer::create();
	maplayer->setName("map");
	this->addChild(maplayer);
	//������̹�˲�
	auto tanklyer = Tanklayer::create();
	tanklyer->setName("tanklyer");
	this->addChild(tanklyer);
	//����з�̹��
	auto enemylayer = EnemyLayer::create();
	enemylayer->setName("enemlayer");
	this->addChild(enemylayer);
	//�߼�
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