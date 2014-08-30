#ifndef __TANKLAYER_H
#define __TANKLAYER_H
#include "cocos2d.h"
#include "Tank.h"
using namespace cocos2d;
class Tanklayer:public Layer{
public:
	bool ispress;
public:
	void onKeyReleased(EventKeyboard::KeyCode keycode, cocos2d::Event *event);
	virtual bool init();
	CREATE_FUNC(Tanklayer);
	static Scene* createScene();
	void update(float t);
private:
	Tank* tank;
};
#endif