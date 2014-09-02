#include "Tanklayer.h"
#include "SimpleAudioEngine.h"
#include "EnemyManager.h"
using namespace CocosDenshion;
bool Tanklayer::init(){
	if(!Layer::init()){
		return false;
	}
	ispress =false;
	tool = nullptr;
	tank = Tank::create();
	tank->setName("tank");
	tank->setPosition(240,16);
	this->addChild(tank);
	//ע�Ჶ׽����	
	auto listenerkeyPad = EventListenerKeyboard::create();
	listenerkeyPad->onKeyPressed = CC_CALLBACK_2(Tanklayer::onKeyReleased, this);
	listenerkeyPad->onKeyReleased = [=](EventKeyboard::KeyCode keycode, cocos2d::Event *event){
		if (this->getChildByName("tank")==nullptr)
		{
			return;
		}
		tank->setisStop(true);
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);
	this->schedule(schedule_selector(Tanklayer::outTool),20);//25����һ������
	this->schedule(schedule_selector(Tanklayer::tankvstool));
	return true;
}

//��׽����
void Tanklayer::onKeyReleased(EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{   
	if (this->getChildByName("tank") == nullptr)
	{
		return;
	}
	
	if (keycode == EventKeyboard::KeyCode::KEY_W)  //��
	{
		ispress = true;
		tank->setState(Up);
		tank->setisStop(false);
	}
	if (keycode == EventKeyboard::KeyCode::KEY_A)  //��
	{
		ispress = true;
		tank->setState(Left);
		tank->setisStop(false);
	}
	if (keycode == EventKeyboard::KeyCode::KEY_D)  //��
	{
		tank->setState(Right);
		tank->setisStop(false);

	}
	if (keycode == EventKeyboard::KeyCode::KEY_S) //��
	{
		tank->setState(Down);
		tank->setisStop(false);
	}
	if (keycode == EventKeyboard::KeyCode::KEY_J)//����

	{
		//auto sid = SimpleAudioEngine::getInstance()->playEffect("bullet.aif");
		tank->fire();
	}

}
void Tanklayer::outTool(float t){
	Tool * tool = nullptr;
	int i =CCRANDOM_0_1()*10;
	if(i<5){
		 tool = Tool::create(1);		
		this->addChild(tool);
	}else{
		tool = Tool::create(2);
		this->addChild(tool);
	}
	tool->setTag(1);
}
void Tanklayer::tankvstool(float t){
	auto tool = (Tool *)this->getChildByTag(1);
	if (this->getChildByName("tank") == nullptr||tool == nullptr)
	{
		return;
	}
if(tank->getBoundingBox().intersectsRect(tool->getBoundingBox())){
		if(tool->getType()==1){
			tank->hurt(-200);
		}else{
			auto vc = EnemyManager::getInstance()->getEnemyManger();
			for(auto it=vc.begin();it!=vc.end();it++){
				(*it)->hurt(100000);
			}
		}
		tool->removeFromParentAndCleanup(true);
	}
}
