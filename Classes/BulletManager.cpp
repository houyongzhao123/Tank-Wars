#include "BulletManager.h"
BulletManager *BulletManager::bulletManger = nullptr;
BulletManager *BulletManager::getInstance()
{
	if (bulletManger==nullptr)
	{
		bulletManger = new BulletManager();
		return bulletManger;
	}
	return bulletManger;
}
void BulletManager::addEnemyBullet(Basebullet * bullet)
{
	enemybullet.pushBack(bullet);
}
void BulletManager::addTankBullet(Basebullet * bullet)
{
	tankbullet.pushBack(bullet);
}
void BulletManager::removeEnemyBullet(Basebullet * bullet)
{
	enemybullet.eraseObject(bullet);
}
void BulletManager::removeTankBullet(Basebullet *bullet)
{
	tankbullet.eraseObject(bullet);
}
void BulletManager::removeAllBullets()
{
	//清除所有无效子弹

}
void BulletManager::cleanAll()
{
	tankbullet.clear();
	enemybullet.clear();
}
Vector<Basebullet *>& BulletManager::getEnemyBulletManger()
{
	return enemybullet;
}
Vector<Basebullet *>& BulletManager::getTankBulletManager()
{
	return tankbullet;
}