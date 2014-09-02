#ifndef __BASETANK_H
#define __BASETANK_H
#include "cocos2d.h"
using namespace cocos2d;
//̹���ƶ�״̬��ö��
enum moverect{
	Up,
	Right,
	Down,
	Left,
	Stop
};
class BaseTank:public Sprite{
protected:
	int speed;//�ƶ�ʱ�ļ��
	//�����һ֡������
	Vec2& getNextFramePostion();
	//̹�˲���ʱ����˸����
	virtual void BlinkAnimation();
	//̹����������
	virtual void dieAnimation();
	//�����ƶ�����,ֻ����̹����ʵ��
	virtual void playMoveEffect()=0;
public:

	CC_SYNTHESIZE(int,hp,Hp);//Ѫ��
	CC_SYNTHESIZE(bool,isstop,isStop)//�Ƿ���ֹͣ״̬
	CC_SYNTHESIZE(bool,isdie,ISdie);//�Ƿ�����
	virtual void hurt(int hp);//���˵�ǰhp-�ӵ�������
	virtual void move(float t);//����ö��״̬ѡ���ƶ�����
	virtual bool boundingBox(Vec2 position);//�ƶ�����ײ���
	virtual bool initWithSpriteFrameName(std::string name,int hp,int speed);
	CC_SYNTHESIZE(moverect,state,State);//��ȡ��ö��״̬�ķ���
	virtual void fire()=0;//���𷽷�
	virtual  void runAnimate()=0;//�����䶯��
	Rect& getNextFrameBoundingBox();//��һ֡λ�����ͼ�ļ��
};
#endif