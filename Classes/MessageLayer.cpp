#include "MessageLayer.h"
#include "GameScene.h"
#include "BaseTank.h"
bool MessageLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto sprite = Sprite::createWithSpriteFrameName("en1.png");
	sprite->setPosition(Vec2(825,400));
	sprite->setTag(1);
	this->addChild(sprite);
	auto sp1 = Sprite::createWithSpriteFrameName("flag.png");
	sp1->setPosition(Vec2(850,200));
	this->addChild(sp1);
	//�о�̹�˼���
	enemycount=20;
	enemystr = StringUtils::format("x %d",enemycount);
	enemylable = Label::createWithSystemFont(enemystr,"Airal",20);
	score=0;
	enemylable->setPosition(870,400);
	this->addChild(enemylable);
	scorestr = StringUtils::format("score:%d",score);
	scorelable = Label::createWithSystemFont(scorestr,"Airal",20);
	scorelable->setPosition(Vec2(850,500));
	this->addChild(scorelable);
	auto center = __NotificationCenter::getInstance();
	center->addObserver(this,callfuncO_selector(MessageLayer::reciveEnemyDie),"EnemyDie",nullptr);//ע��о�����֪ͨ 
	return true;
}
void MessageLayer::reciveEnemyDie(Ref * obj)
{
	enemycount--;
	if (enemycount<0)
	{
		enemycount = 999;
	}
	//������ӹؿ�����
	enemystr = StringUtils::format("x %d",enemycount);
	enemylable->setString(enemystr);
	score = score+10;
	scorestr = StringUtils::format("score:%d",score);
	scorelable->setString(scorestr);
	//�����ı�
}
void MessageLayer::onEnter()
{
	Layer::onEnter();
	auto scene =dynamic_cast<GameScene *> (Director::getInstance()->getRunningScene());
	auto tank = (BaseTank*)scene->getTanklayer()->getChildByName("tank");
	if (tank == nullptr)
	{
		return;
	}//�ж�Tank�Ƿ�Ϊ��
	auto center = __NotificationCenter::getInstance();
	center->addObserver(this,callfuncO_selector(MessageLayer::reciveTankHurt),"TankHurt",tank);
	tankHP = tank->getHp();
	tankHPstr = StringUtils::format("HP x %d",tankHP);
	tankHPlable = Label::createWithSystemFont(tankHPstr,"Airal",20);
	tankHPlable->setPosition(850,150);
	this->addChild(tankHPlable);

}
void MessageLayer::reciveTankHurt(Ref *obg)
{
	tankHP = ((BaseTank *)(obg))->getHp();
	tankHPstr = StringUtils::format("HPx %d",tankHP);
	tankHPlable->setString(tankHPstr);
}
//��Ϣ����
MessageLayer::~MessageLayer()
{
	auto center = __NotificationCenter::getInstance();
	center->removeAllObservers(this);
}
//ж����Ϣ����