#include "GameScene.h"
#include "MapLayer.h"
#include "Tanklayer.h"
#include "EnemyLayer.h"
#include "LogicLayer.h"
#include "MessageLayer.h"
#include "SimpleAudioEngine.h"
#include "ControlLayer.h"
using namespace CocosDenshion;
bool GameScene::init(){
	if(!Scene::init()){
		return false;
	}
	//����֡����ͼƬ
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image.plist");
	SimpleAudioEngine::getInstance()->playEffect("02 start.aif");
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
	//�����߼���
    auto logiclayer = LogicLayer::create();
	this->addChild(logiclayer);
	//������Ϣ��
	auto messagelayer = MessageLayer::create();
	this->addChild(messagelayer);
	//������Ʋ�
	auto controllayer = ControlLayer::create();
	controllayer->bindControlTarget((BaseTank *)tanklyer->getChildByName("tank"));
	this->addChild(controllayer);
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