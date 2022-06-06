#include "PotatoMine.h"

void PotatoMine::prepareDone(float dt) {
	this->buff = true;
	this->health = 1000;
	m_body->runAction(RepeatForever::create(Animate::create(animation)));
}

bool PotatoMine::init() {
	if (!Node::init()) return false;
	auto animation = Animation::create();
	animation->addSpriteFrameWithFile("Plants/PotatoMiner/1.png");
	animation->addSpriteFrameWithFile("Plants/PotatoMine/2.png");
	animation->addSpriteFrameWithFile("Plants/PotatoMine/3.png");
	animation->addSpriteFrameWithFile("Plants/PotatoMine/4.png");
	animation->addSpriteFrameWithFile("Plants/PotatoMine/5.png");
	animation->setDelayPerUnit(0.1f);
	m_body = Sprite::create("Plants/PotatoMine/0.png");
	//
	this->type = 6;
	m_body->setScale(0.6f);
	this->addChild(m_body);
	m_body->setAnchorPoint(Vec2(0.0, 0.0));
	//interval = 1.4f;
	health = 300;
	//schedule(CC_CALLBACK_1(SunFlower::produceSun, this), 24.0, "sun1");
	scheduleOnce(CC_CALLBACK_1(PotatoMine::prepareDone, this), 9 + rand() % 3, "prdone");
	//schedule(CC_CALLBACK_1(Plant::bulletChecker, this), 1.0f, "Checker");
	return true;
}