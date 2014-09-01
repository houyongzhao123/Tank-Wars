#ifndef __ENEMYTANK_H
#define __ENEMYTANK_H
#include "cocos2d.h"
#include "BaseTank.h"
using namespace cocos2d;
class EnemyTank:public BaseTank{
protected:
	Vec2 position;
	//��̹�˵������ƶ��Ϳ���
	virtual void update(float t);
public:
//	virtual void move(moverect State);//��̹�˵��ƶ�����
	virtual bool initWithSpriteFrameName(std::string name,int hp,int speed,Vec2 position);
	virtual void addBulletToManager(Basebullet *);//ʵ�ֻ�����ӵ��������ķ���
	virtual  void runAnimate();
	CREATE_FUNC(EnemyTank);
	
};
#endif