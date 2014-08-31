#ifndef __TANK_H
#define __TANK_H
#include "cocos2d.h"
#include "BaseTank.h"
#define TANKHP 500
#define SPEED 8
using namespace cocos2d;
class Tank:public BaseTank{
public:
	virtual void fire();
	virtual  void runAnimate();
	virtual bool init();
	static Tank* create();
};
#endif