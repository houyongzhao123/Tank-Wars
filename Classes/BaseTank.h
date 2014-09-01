#ifndef __BASETANK_H
#define __BASETANK_H
#include "cocos2d.h"
#include "Basebullet.h"
using namespace cocos2d;
enum moverect{
	Up,
	Right,
	Down,
	Left,
	Stop
};
class BaseTank:public Sprite{
protected:
	int hp;//Ѫ��
	int speed;//�ƶ�ʱ�ļ��
	Vec2& getNextFramePostion();
	float bulletCoolTime;
public:
	CC_SYNTHESIZE(bool,isstop,isStop)
	CC_SYNTHESIZE(bool,isdie,ISdie);//�Ƿ�����
	virtual void hurt(int hp);//���˵�ǰhp-�ӵ�������
	virtual void move(float t);//����ö��״̬ѡ���ƶ�����
	virtual bool initWithSpriteFrameName(std::string name,int hp,int speed);
	CC_SYNTHESIZE(moverect,state,State);//��ȡ��ö��״̬�ķ���
	virtual void fire();//���𷽷�
	virtual void addBulletToManager(Basebullet *) = 0;//�����ӵ�����
	virtual  void runAnimate()=0;//�����䶯��
	Rect& getNextFrameBoundingBox();
};
#endif