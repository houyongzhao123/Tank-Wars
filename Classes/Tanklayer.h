#ifndef __TANKLAYER_H
#define __TANKLAYER_H
#include "cocos2d.h"
#include "Tank.h"
#include "Tool.h"
using namespace cocos2d;
class Tanklayer:public Layer{
public:
	bool ispress;
public:
	void onKeyReleased(EventKeyboard::KeyCode keycode, cocos2d::Event *event);//��������
	virtual bool init();
	CREATE_FUNC(Tanklayer);
private:
	virtual void outTool(float t);//���ֵ���
	virtual void tankvstool(float t);//���
	Tank* tank;
	Tool* tool;
};
#endif