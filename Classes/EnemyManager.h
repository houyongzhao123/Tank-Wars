#ifndef __ENEMYMANAGER_H
#define __ENEMYMANAGER_H
#include "cocos2d.h"
#include "BaseTank.h"
USING_NS_CC;
//�ӵ�������
class EnemyManager
{  
	static EnemyManager *enemyManger;
	Vector<BaseTank*> enemyVector;
public:
	void addEnemy(BaseTank * tank);//��ӵо�
	void removeEnemy(BaseTank * tank);//�Ƴ��о�
	void removeAllenemys();//�Ƴ����ео�
	void cleanAll();
	Vector<BaseTank*>& getEnemyManger();//��ȡ�о��ӵ�����
	static EnemyManager* getInstance();
};
#endif // !__BULLTMANAGER_H
