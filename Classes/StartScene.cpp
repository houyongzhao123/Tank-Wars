#include "StartScene.h"
#include "GameScene.h"
#include "AudioRes.h"
bool StartScene::init(){
	if (!Scene::init()){
		return false;
	}
	//���̹�������ͼƬ
	AudioInit();
	auto title = Sprite::create("BattleCity.png");
	title->setNormalizedPosition(Vec2(0.5, 0.6));
	this->addChild(title);
	//��ӿ�ʼ��Ϸ�İ�ť
	auto item = MenuItemFont::create("StartGame", [](Ref*){
		Director::getInstance()->replaceScene(GameScene::create());
	});
	auto menu = Menu::create(item, nullptr);
	menu->setPosition(0, 0);
	item->setNormalizedPosition(Vec2(0.5,0.2));
	this->addChild(menu);
	return true;
}
