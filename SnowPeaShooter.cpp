#include "SnowPeaShooter.h"

bool SnowPeaShooter::init() {
	Plant::_init();
	if (!Node::init()) return false;
	auto animation = Animation::create();
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/1.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/2.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/3.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/4.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/5.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/6.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/7.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/8.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/9.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/10.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/11.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/12.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/13.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/14.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/15.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/16.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/17.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/18.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/19.png");
	animation->addSpriteFrameWithFile("Plants/SnowPeaShooter/20.png");
	animation->setDelayPerUnit(0.06f);
	auto animate = Animate::create(animation);
	m_body = Sprite::create("Plants/SnowPeaShooter/1.png");
	m_body->runAction(RepeatForever::create(animate));
	m_body->setScale(0.7f);
	this->addChild(m_body);
	m_body->setAnchorPoint(Vec2(0.2, 0.2));
	interval = 1.4f;
	health = 300;
	srand(time(0));
	schedule(CC_CALLBACK_1(SnowPeaShooter::shot, this), interval, "SnowShot");
	schedule(CC_CALLBACK_1(Plant::bulletChecker, this), 1.0f, "Checker");
	return true;
}

void SnowPeaShooter::shot(float dt) {
	if (!haveZombieInArea) return;
	if (m_space) {
		auto pea = SnowPea::create();
		pea->setPosition(getPositionX() + 64, getPositionY() + 80);
		pea->setLine(this->line);
		pea->runAction(MoveBy::create(4, Vec2(1536, 0)));
		m_space->addChild(pea);
		//bullets.insert(pea);
		bullets.pushBack(pea);
		if (rand() < 3277) {
			pea->buff = true;
		}
	}
}