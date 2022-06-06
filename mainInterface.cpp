#include "mainInterface.h"
#include "global.h"

bool mainInterface::init() {
	if (!Scene::init()) return false;
	auto backGround = Sprite::create("Scence/mainInterface.png");
	backGround->setAnchorPoint(Vec2(0, 0));
	backGround->setPosition(Vec2(-128, -128));
	this->addChild(backGround);

	auto chooseDayItem = MenuItemImage::create(
		"Scence/day.png", "Scence/day.png", "Scence/day.png",
		CC_CALLBACK_1(mainInterface::DayScence, this));
	auto dayMenu = Menu::create(chooseDayItem, NULL);
	dayMenu->setPosition(Vec2(220, 200));
	this->addChild(dayMenu, 0);

	auto chooseNightItem = MenuItemImage::create(
		"Scence/Night.png", "Scence/Night.png", "Scence/Night.png",
		CC_CALLBACK_1(mainInterface::NightScence, this));
	auto NightMenu = Menu::create(chooseNightItem, NULL);
	NightMenu->setPosition(Vec2(1060, 200));
	this->addChild(NightMenu, 0);
	zomGen = zombiesGenerator::create();
	zomGen->setDisabled(true);
	auto easyLabel = Menu::create(MenuItemImage::create("Scence/easyLabel.png", "Scence/easyLabel.png", "Scence/easyLabel.png", 
		CC_CALLBACK_1(mainInterface::setEasyMode, this)), NULL);
	
	auto midLabel = Menu::create(MenuItemImage::create("Scence/midLabel.png", "Scence/midLabel.png", "Scence/midLabel.png",
	CC_CALLBACK_1(mainInterface::setMidMode, this)), NULL);

	auto midHardLabel = Menu::create(MenuItemImage::create("Scence/midHardLabel.png", "Scence/midHardLabel.png", "Scence/midHardLabel.png",
		CC_CALLBACK_1(mainInterface::setMidHardMode, this)), NULL);

	auto hardLabel = Menu::create(MenuItemImage::create("Scence/hardLabel.png", "Scence/hardLabel.png", "Scence/HardLabel.png",
		CC_CALLBACK_1(mainInterface::setHardMode, this)), NULL);

	auto right = Sprite::create("Scence/right.png");
	right->setPosition(Vec2(160, 500));
	this->addChild(right);


	easyLabel->setPosition(Vec2(570, 320));
	midLabel->setPosition(Vec2(570, 200));
	midHardLabel->setPosition(Vec2(730, 320));
	hardLabel->setPosition(Vec2(730, 200));

	this->addChild(easyLabel); this->addChild(midLabel);
	this->addChild(midHardLabel); this->addChild(hardLabel);
	levelLabel = Label::createWithSystemFont("Level:Easy", "Arial", 50);
	levelLabel->setPosition(Vec2(640, 96));
	this->addChild(levelLabel);


	return true;
}

void mainInterface::DayScence(cocos2d::Ref* pSender) {
	Director::getInstance()->pushScene(this);
	auto _scence = mainGameDay::create();
	Director::getInstance()->replaceScene(TransitionFade::create(1.5, _scence, Color3B(64, 255, 64)));
	Director::getInstance()->resume();
}

void mainInterface::NightScence(cocos2d::Ref* psender) {
	Director::getInstance()->pushScene(this);
	auto _scence = mainGameNight::create();
	Director::getInstance()->replaceScene(TransitionFade::create(1.5, _scence, Color3B(96, 96, 96)));
	Director::getInstance()->resume();
}

void mainInterface::setEasyMode(Ref* pSender) {
	zomGen->setHardLevel(1);
	zomGen->setRoundCount(10);
	levelLabel->setString(std::string("Level:Easy"));
}

void mainInterface::setMidMode(Ref* pSender) {
	zomGen->setHardLevel(3);
	zomGen->setRoundCount(15);
	levelLabel->setString(std::string("Level:Mid"));
}

void mainInterface::setMidHardMode(Ref* pSender) {
	zomGen->setHardLevel(4);
	zomGen->setRoundCount(15);
	levelLabel->setString(std::string("Level:High"));
}

void mainInterface::setHardMode(Ref* pSender) {
	zomGen->setHardLevel(5);
	zomGen->setRoundCount(20);
	levelLabel->setString("Level:Ultra");
}

