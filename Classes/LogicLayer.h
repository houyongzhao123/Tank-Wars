#ifndef __LOGICLAYER_H
#define __LOGICLAYER_H
#include "cocos2d.h"
USING_NS_CC;
class LogicLayer:public Layer
{  
    Label *scorelable;
	std::string scorestr;
	int enemycount;
	Label *enemylable;
	std::string enemystr;
public:
	CC_SYNTHESIZE(int,score,Score);
	virtual bool init();
	CREATE_FUNC(LogicLayer);
	void TankTestBound();//˫��̹����ײ
	void BulletTestBound();
	void bulletEvsT(); //�о��ӵ��ͼ����ӵ���ײ
	void bulletvsBarrer();//�ӵ���ǽ
	void bulletVsEnemy();//�����ӵ��͵о�
	void bulletVsTank();//�з��ӵ�������
	void reciveEnemyDie(Ref * obj);
	void update(float);
};
#endif // !__LOGICLAYER_H
