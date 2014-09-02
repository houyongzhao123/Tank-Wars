#include "ControlLayer.h"

ControlLayer *ControlLayer::shareControl = nullptr;
bool ControlLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//����ҡ�˵�ͼƬ����
	auto joyStick = Sprite::create("control_bg.png");
	this->addChild(joyStick);
	joyStick->setPosition(100, 100);
	joyStick->setOpacity(100);
	//����ҡ���ϵĿ������ľ���
	auto stick = Sprite::create("cen.png");
	stick->setOpacity(150);
	stick->setVisible(false);
	stick->setNormalizedPosition(Vec2(0.5, 0.5));
	joyStick->addChild(stick);

	auto lisenter = EventListenerTouchOneByOne::create();
	lisenter->onTouchBegan = [=](Touch *touch, Event* event){
		//��ȡ������ 
		auto point = touch->getLocation();
		auto j_point = joyStick->getPosition();
		if (sqrt((point.x - j_point.x)*(point.x - j_point.x) + (point.y - j_point.y)*(point.y - j_point.y))<joyStick->getContentSize().width/2){

			stick->setVisible(true);
			stick->setPosition(point);

		}
		return true;

	};
	lisenter->onTouchMoved = [=](Touch *touch, Event* event){
		//��ȡ������ 
		auto point = touch->getLocation();
		auto j_point = joyStick->getPosition();
		if (sqrt((point.x - j_point.x)*(point.x - j_point.x) + (point.y - j_point.y)*(point.y - j_point.y)) < joyStick->getContentSize().width / 2+10){

			/*stick->setVisible(true);*/
			stick->setPosition(point);

			//�ж��ƶ�����
			int sub_x = point.x - j_point.x;
			int sub_y = point.y - j_point.y;

			if (tank == nullptr)
			{
				return ;
			}

			if (sub_y > 0 && sub_y > abs(sub_x))  //��
			{
				tank->setState(Up);
				tank->setisStop(false);
			}
			if (sub_x<0 && abs(sub_x)>abs(sub_y))  //��
			{
				tank->setState(Left);
				tank->setisStop(false);
			}
			if (sub_x > 0 && abs(sub_x) > abs(sub_y))  //��
			{
				tank->setState(Right);
				tank->setisStop(false);

			}
			if (sub_y<0 && abs(sub_y)>abs(sub_x)) //��
			{
				tank->setState(Down);
				tank->setisStop(false);
			}
		}
		else
		{
			stick->setPosition(joyStick->getPosition());
		}


	};
	lisenter->onTouchEnded = [=](Touch *touch, Event* event){
		stick->setVisible(false);
		if (tank == nullptr)
		{
			return;
		}
		tank->setisStop(true);
	};

	//���÷����ӵ��İ�ť
	auto fireItem = MenuItemImage::create("fire_button_default.png", "fire_button_press.png", [=](Ref* pSender){

		if (tank == nullptr)
		{
			return;
		}
		tank->fire();
	});
	fireItem->setPosition(700,100);
	fireItem->setOpacity(120);
	auto menu = Menu::create(fireItem, nullptr);
	menu->setPosition(0, 0);
	this->addChild(menu,1);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(lisenter,this);
	return true;
}
void ControlLayer::bindControlTarget(BaseTank *tank)
{
	if (this->tank != tank)
	{
		CC_SAFE_RELEASE(this->tank);
		CC_SAFE_RETAIN(tank);
		this->tank = tank;
	}
}