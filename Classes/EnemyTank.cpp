#include "EnemyTank.h"
#include "Basebullet.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "GameScene.h"
bool EnemyTank::initWithSpriteFrameName(std::string name,int hp,int speed,Vec2 position){
	if(!BaseTank::initWithSpriteFrameName(name,hp,speed)){
		return false;
	}
	this->position=position;
	this->setPosition(position);
	//�ѵ�̹��������̹�˲�
	auto scene = dynamic_cast<GameScene*>(Director::getInstance()->getRunningScene());
	auto elayer = scene->getenemlayer();
	elayer->addChild(this);
	//�ѵз�̹�˼��뵽̹��������
	EnemyManager::getInstance()->addEnemy(this);
	//��ʱ�����ƶ�
	this->schedule(schedule_selector(EnemyTank::update),5);
	return true;
}
void EnemyTank::addBulletToManager(Basebullet * bullet){
	//�ѵз��ӵ��ӵ��з��ӵ�������
	BulletManager::getInstance()->addEnemyBullet(bullet);
}
void EnemyTank::runAnimate(){

}
void EnemyTank::update(float t){
	this->fire();
}
//2014-9-1 17:13:57�Ƴ�fire,����addaddBulletToManager