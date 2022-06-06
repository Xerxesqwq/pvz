#include "NutWall.h"

bool NutWall::init() {
	if (!Node::init()) return false;
	auto animation = Animation::create();
	animation->addSpriteFrameWithFile("Plants/NutWall/jian1.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian2.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian3.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian4.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian5.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian6.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian7.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian8.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian9.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian10.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian11.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian12.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian13.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian14.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian15.png");
	animation->addSpriteFrameWithFile("Plants/NutWall/jian16.png");
	animation->setDelayPerUnit(0.08f);
	auto animate = Animate::create(animation);
	m_body = Sprite::create("Plants/NutWall/jian1.png");
	m_body->runAction(RepeatForever::create(animate));
	m_body->setScale(1.2f);
	//m_body->setPosition(Vec2(0, 0));
	this->addChild(m_body);
	m_body->setAnchorPoint(Vec2(-0.1, 0));
	interval = 0.0f;
	health = 4000;
	bloodBar = LoadingBar::create("Scence/loadingBar.png");
	bloodBar->setPercent(100.0f);
	bloodBar->setPosition(m_body->getPosition() + Vec2(48, 128));
	this->addChild(bloodBar);
	schedule(CC_CALLBACK_1(NutWall::updateBlood, this), 0.05f, "updntwbld");
	schedule(CC_CALLBACK_1(NutWall::recoverBlood, this), 1.0f, "rcvbld");
	//schedule(CC_CALLBACK_1(Plant::bulletChecker, this), 1.0f, "Checker");
	return true;
}

void NutWall::recoverBlood(float dt) {
	if (this->health <= 0) return;
	if (health + 10.0 <= maxHealth) health = health + 20 + 20 * (4000 - health) / 4000;
}

void NutWall::updateBlood(float dt) {
	bloodBar->setPercent(health * 100.0f / maxHealth);
	//if (health + (health << 1) < maxHealth)
	//	bloodBar->setColor(Color3B(192, 255, 0));
}
