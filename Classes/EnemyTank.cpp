#include "EnemyTank.h"
#include "Basebullet.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "GameScene.h"
#include "BulletManager.h"
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
	//��ʱ�ƶ�ת��
	this->schedule(schedule_selector(EnemyTank::Enemymove),2);
	//��ʱ����
	this->schedule(schedule_selector(EnemyTank::update),2);
	return true;
}
void EnemyTank::fire(){
	auto enemybullet = Basebullet::Createbullet(this->getPosition(),this->getState());
	//�ѵз��ӵ��ӵ��з��ӵ�������
	BulletManager::getInstance()->addEnemyBullet(enemybullet);
}
void EnemyTank::runAnimate(){

}
void EnemyTank::update(float t){
	int n = BulletManager::getInstance()->getEnemyBulletManger().size();
	if(n<=9){
	this->fire();
	}else
	{
		return;
	}
}
void EnemyTank::Enemymove(float t){
	this->setisStop(false);
	int num = rand()%6;
	//moverect i =(moverect)num;
	if(num>=0&&num<1){
		moverect i=(moverect)0;
		this->setState(i);
	}else if(num>=1&&num<2){
		moverect i=(moverect)1;
		this->setState(i);
	}else if(num>=2&&num<5){
		moverect i=(moverect)2;
		this->setState(i);
	}else if(num>=5&&num<6)
	{
		moverect i=(moverect)3;
		this->setState(i);
	}	
}
void EnemyTank::playMoveEffect()
{

}