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
	int hp;//血量
	int speed;//移动时的间距
	Vec2& getNextFramePostion();
	float bulletCoolTime;
public:
	CC_SYNTHESIZE(bool,isstop,isStop)
	CC_SYNTHESIZE(bool,isdie,ISdie);//是否死亡
	virtual void hurt(int hp);//受伤当前hp-子弹攻击力
	virtual void move(float t);//根据枚举状态选择移动方向
	virtual bool initWithSpriteFrameName(std::string name,int hp,int speed);
	CC_SYNTHESIZE(moverect,state,State);//获取其枚举状态的方法
	virtual void fire();//开火方法
	virtual void addBulletToManager(Basebullet *) = 0;//加入子弹管理
	virtual  void runAnimate()=0;//运行其动画
	Rect& getNextFrameBoundingBox();
};
#endif