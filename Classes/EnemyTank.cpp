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
	//把敌坦克贴到敌坦克层
	auto scene = dynamic_cast<GameScene*>(Director::getInstance()->getRunningScene());
	auto elayer = scene->getenemlayer();
	elayer->addChild(this);
	//把敌方坦克加入到坦克容器中
	EnemyManager::getInstance()->addEnemy(this);
	return true;
}
void EnemyTank::fire(){
	auto enemybullet = Basebullet::Createbullet(this->getPosition(),this->getState());
	//把敌方子弹加到敌方子弹容器中
	BulletManager::getInstance()->addEnemyBullet(enemybullet);
}
void EnemyTank::runAnimate(){

}