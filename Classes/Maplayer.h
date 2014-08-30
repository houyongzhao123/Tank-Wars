#ifndef __MAPLAYER_H
#define __MAPLAYER_H
#include "cocos2d.h"
USING_NS_CC;

class MapLayer :public Layer{
public: 
	virtual bool init();
	CREATE_FUNC(MapLayer);

	Vec2 getState(int i);

	//����Ƿ�����ж��� �Ƿ���ƻ�
	bool checkNodeBreak(Vec2 position);
	bool checkIsNode(Vec2 position);
private:
	float offX;//���,��Ϊ��ͼλ�øı��,ƫ������ʵ��x�����ƶ���960*0.2=192;
	TMXTiledMap* map;//��ͼ�Ĳ�
	//��ͼ�ϵĶ�������ļ���
	TMXObjectGroup* object;
	Vector<Node*> pointsVector;
	void initPointsVector(float offX);
	TMXLayer* bgLayer;//��ͼ�ı�����
	TMXLayer* bossLayer;//��ͼ��boss����һǹ����


	//ת������
	Vec2 converTotileCoord(Vec2 position);//ת��Ϊ��ͼ����
	//Vec2 converToMatrixCoord(Vec2 position);//ת��Ϊ��������

};
#endif