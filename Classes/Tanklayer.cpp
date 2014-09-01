#include "Tanklayer.h"
bool Tanklayer::init(){
	if(!Layer::init()){
		return false;
	}
	ispress =false;
	tank = Tank::create();
	tank->setName("tank");
	tank->setPosition(Vec2(480,320));
	this->addChild(tank);
	//ע�Ჶ׽����	
	auto listenerkeyPad = EventListenerKeyboard::create();
	listenerkeyPad->onKeyPressed = CC_CALLBACK_2(Tanklayer::onKeyReleased, this);
	listenerkeyPad->onKeyReleased = [=](EventKeyboard::KeyCode keycode, cocos2d::Event *event){tank->setisStop(true);};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);
	return true;
}
//��׽����
void Tanklayer::onKeyReleased(EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{   
	if (tank == nullptr)
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
		tank->fire();
	}

}
