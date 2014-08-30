#ifndef __BASETANK_H
#define __BASETANK_H
#include "cocos2d.h"
using namespace cocos2d;
enum moverect{
	Up,
	Down,
	Left,
	Right,
	Stop
};
class BaseTank:public Sprite{
protected:
	int hp;
	int speed;

public:
	virtual void move(moverect State);
	virtual bool initWithSpriteFrameName(std::string name,int hp,int speed);
	CC_SYNTHESIZE(moverect,state,State);
	virtual void fire()=0;
	virtual  void runAnimate()=0;
};
#endif