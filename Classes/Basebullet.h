#ifndef __BASEBULLET_H
#define __BASEBULLET_H
#include "cocos2d.h"
#define YIDONGSUDU 200
#define BULLETATTACK 50
using namespace cocos2d;
enum moverect;
class Basebullet:public Sprite{
public:
	CC_SYNTHESIZE_READONLY(int,Attack,ATTACK);//�ӵ��Ĺ������Ķ�ȡ
	static Basebullet* Createbullet(Vec2 position,moverect STATE);
	virtual bool initWithTank(Vec2 position,moverect STATE);
	virtual void move();//�ӵ����ƶ�����
	virtual void remove();//���Ƴ���Ļ���ӵ�Ū��
	CC_SYNTHESIZE(bool,isdie,ISDIE);//��ȡ�ӵ��Ƿ�����
private:
	int sid;
	moverect STATE;//ö��״̬
	Size vsize;//��Ļ�ߴ�
	Vec2 position;//��ʼλ��
};
#endif