#ifndef __TOOL_H
#define __TOOL_H
#include "cocos2d.h"
using namespace cocos2d;
class Tool:public Sprite{
protected:
	void cleanfrom(float t);
public:
	CC_SYNTHESIZE_READONLY(int, type, Type);
	//type = 1 ��ʾ��Ѫ type = 2��ʾը��
	virtual bool init(int type);
	static Tool * create(int type);

};
#endif