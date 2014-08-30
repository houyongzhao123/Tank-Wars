#include "Tanklayer.h"
bool Tanklayer::init(){
	if(!Layer::init()){
		return false;
	}
	ispress =false;
	tank = Tank::create();
	tank->setPosition(Vec2(480,320));
	tank->setName("tank");
	this->addChild(tank);
	//×¢²á²¶×½¼àÌı	
	auto listenerkeyPad = EventListenerKeyboard::create();
	listenerkeyPad->onKeyPressed = CC_CALLBACK_2(Tanklayer::onKeyReleased, this);
	listenerkeyPad->onKeyReleased = [=](EventKeyboard::KeyCode keycode, cocos2d::Event *event){ispress =false;};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);
	this->scheduleUpdate();
	return true;
}
//²¶×½¼àÌı
void Tanklayer::onKeyReleased(EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{   

	if (keycode == EventKeyboard::KeyCode::KEY_W)  //ÉÏ
	{
		ispress = true;
		tank->setState(Up);

	}
	if (keycode == EventKeyboard::KeyCode::KEY_A)  //×ó
	{
		ispress = true;
		tank->setState(Left);
	}
	if (keycode == EventKeyboard::KeyCode::KEY_D)  //ÓÒ
	{
		ispress = true;
		tank->setState(Right);
	}
	if (keycode == EventKeyboard::KeyCode::KEY_S) //ÏÂ
	{
		ispress = true;
		tank->setState(Down);
	}
	if (keycode == EventKeyboard::KeyCode::KEY_J)//·¢»ğ

	{
		tank->fire();
	}

}
void Tanklayer::update(float t){   

	if (ispress)
	{   
		tank->move(tank->getState());
	}
}