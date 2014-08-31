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
	return true;
}
void EnemyTank::fire(){
	auto enemybullet = Basebullet::Createbullet(this->getPosition(),this->getState());
	//�ѵз��ӵ��ӵ��з��ӵ�������
	BulletManager::getInstance()->addEnemyBullet(enemybullet);
}
void EnemyTank::runAnimate(){

}