#ifndef __BASEBULLET_H
#define __BASEBULLET_H
#include "cocos2d.h"
#define YIDONGSUDU 200
using namespace cocos2d;
enum moverect;
class Basebullet:public Sprite{
public:
	static Basebullet* Createbullet(Vec2 position,moverect STATE);
	virtual bool initWithTank(Vec2 position,moverect STATE);
	virtual void move();
private:
	moverect STATE;
	Size vsize;
	Vec2 position;
};
#endif