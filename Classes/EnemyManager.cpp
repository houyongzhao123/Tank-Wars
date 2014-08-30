#include "EnemyManager.h"
EnemyManager *EnemyManager::enemyManger = nullptr;
EnemyManager *EnemyManager::getInstance()
{
	if (enemyManger==nullptr)
	{
		enemyManger = new EnemyManager();
		return enemyManger;
	}
	return enemyManger;
}
void EnemyManager::addEnemy(BaseTank * tank)
{
	enemyVector.pushBack(tank);
}

void EnemyManager::removeEnemy(BaseTank * tank)
{
	enemyVector.eraseObject(tank);
}

void EnemyManager::removeAllenemys()
{

}
void EnemyManager::cleanAll()
{
	enemyVector.clear();
}
Vector<BaseTank*>& EnemyManager::getEnemyManger()
{
	return enemyVector;
}