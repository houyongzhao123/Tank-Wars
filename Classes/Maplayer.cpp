#include "MapLayer.h"


bool MapLayer::init(){
	if (!Layer::init()){
		return false;
	}
	auto bg = Sprite::create("background.jpg");
	this->addChild(bg, -2);
	bg->setNormalizedPosition(Vec2(0.5, 0.5));
	

	//��ͼ������
	map = TMXTiledMap::create("map.tmx");


	//���õĵ�ͼ�еı�����
	bgLayer = map->getLayer("bg");
	bgLayer->setNormalizedPosition(Vec2(0.2,0));
	bossLayer = map->getLayer("boss");
	bossLayer->setVisible(false);
	//ƫ��
	offX = this->getContentSize().width*0.2 - 48;
		
	this->addChild(map,-1);

	//������ȡ
	object = map->getObjectGroup("obj");
	//��ʼ�������
	initPointsVector(offX);
// 	log("%d", checkNodeBreak(Vec2(100, 500)));
// 	log("%d", checkNodeBreak(Vec2(100, 100)));
// 	auto sp = Sprite::createWithSpriteFrameName("p1.png");
// 	sp->setPosition(pointsVector.at(0)->getPosition());
// 	this->addChild(sp);
// 	auto sp1 = Sprite::createWithSpriteFrameName("p1.png");
// 	sp1->setPosition(pointsVector.at(1)->getPosition());
// 	this->addChild(sp1);
// 	auto sp2 = Sprite::createWithSpriteFrameName("p1.png");
// 	sp2->setPosition(pointsVector.at(2)->getPosition());
// 	this->addChild(sp2);
// 	auto sp3 = Sprite::createWithSpriteFrameName("p1.png");
// 	sp3->setPosition(pointsVector.at(3)->getPosition());
// 	this->addChild(sp3);

// 	auto sp1 = Sprite::createWithSpriteFrameName("p1.png");
// 	sp1->setPosition(pointsVector.at(1)->getPosition());
// 	this->addChild(sp1);
// 	auto sp2 = Sprite::createWithSpriteFrameName("p1.png");
// 	sp2->setPosition(pointsVector.at(2)->getPosition());
// 	this->addChild(sp2);
// 	auto sp3 = Sprite::createWithSpriteFrameName("p1.png");
// 	sp3->setPosition(pointsVector.at(3)->getPosition());
// 	this->addChild(sp3);
	return true;
}
//��ȡ�����
void MapLayer::initPointsVector(float offX){
	Node* runOfPoint = nullptr;

	//1
	int count = 1;
	ValueMap point;
	
	//2
	while (count<5)
	{
		point = object->getObject(std::to_string(count));
	
		//3
		auto x = point.at("x").asFloat();
		auto y = point.at("y").asFloat();
		//4
		runOfPoint = Node::create();
		runOfPoint->setPosition(Vec2(x + offX , y));
		this->pointsVector.pushBack(runOfPoint);
		//point = object->getObject(std::to_string(count));
		count++;
		
	runOfPoint = nullptr;
	}
}
//���������0~3
Vec2 MapLayer::getState(int i){
	Vec2 point = pointsVector.at(i)->getPosition();
	return point;
}
//�����ת��
//����
Vec2 MapLayer::converTotileCoord(Vec2 position){
	int x = (position.x - offX) / map->getContentSize().width*map->getMapSize().width;
	int y = map->getMapSize().height - position.y / map->getContentSize().height*map->getMapSize().height;
	return Vec2(x, y);
}
// Vec2 MapLayer::converToMatrixCoord(Vec2 position){
// 	int x = (position.x + offX) / map->getContentSize().width*map->getMapSize().width;
// 	int y = position.y / map->getContentSize().height*map->getMapSize().height;
// 	return Vec2(x, y);
// }

//����Ƿ��ж���
bool MapLayer::checkIsNode(Vec2 position){
	Vec2 towerCoord = converTotileCoord(position);//��ͼ����
	//Vec2 matrixCoord = converToMatrixCoord(position);//����λ��
	if (towerCoord.x>=40||towerCoord.x<= 0)
	{
		return false;
	}
	int gid = bgLayer->getTileGIDAt(towerCoord);//�õ�gid
	//�õ��˸�ͼ���GID����ͨ�������ж��Ƿ�������ӵ����
	if (!gid){
		return false;
	}return true;
}


//����Ƿ�����ƻ�
bool MapLayer::checkNodeBreak(Vec2 position){
	Vec2 towerCoord = converTotileCoord(position);//��ͼ����
	//Vec2 matrixCoord = converToMatrixCoord(position);//����λ��
	int gid = bgLayer->getTileGIDAt(towerCoord);//�õ�gid
	//�õ��˸�ͼ���GID����ͨ�������ж��Ƿ�������ӵ����
	 
	auto titleTemp =  (map->getPropertiesForGID(gid).asValueMap());

	bool BreakValue;
	
	BreakValue = titleTemp.at("canBreak").asBool();
	return BreakValue;

}