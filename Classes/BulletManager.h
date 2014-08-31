#ifndef __BULLETMANAGER_H
#define __BULLETMANAGER_H
#include "cocos2d.h"
#include "Basebullet.h"
USING_NS_CC;
//�ӵ�������
class BulletManager
{  
	static BulletManager *bulletManger;
   Vector<Basebullet*> enemybullet;//�з��ӵ�����
   Vector<Basebullet*> tankbullet;//�ҷ�̹���ӵ�����
public:
	void addEnemyBullet(Basebullet * bullet);//��Ӽ����ӵ�
	void addTankBullet(Basebullet * bullet);//���̹���ӵ�
	void removeEnemyBullet(Basebullet * bullet);//�Ƴ��о��ӵ�
	void removeTankBullet(Basebullet * bullet);//�Ƴ�̹���ӵ�
	void removeAllBullets();//�Ƴ������ӵ�
	void cleanAll();
	Vector<Basebullet*>& getEnemyBulletManger();//��ȡ�о��ӵ�����
	Vector<Basebullet*>& getTankBulletManager();//��ȡ�ҷ��ӵ�����
	static BulletManager* getInstance();
};
#endif // !__BULLTMANAGER_H
