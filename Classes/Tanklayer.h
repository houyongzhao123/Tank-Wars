#ifndef __TANKLAYER_H
#define __TANKLAYER_H
#include "cocos2d.h"
#include "Tank.h"
using namespace cocos2d;
class Tanklayer:public Layer{
public:
	bool ispress;
public:
	void onKeyReleased(EventKeyboard::KeyCode keycode, cocos2d::Event *event);//°´¼ü¼àÌý
	virtual bool init();
	CREATE_FUNC(Tanklayer);
private:
	Tank* tank;
};
#endif