#include "Peashooter.h"

bool Peashooter::init() {
	if (!Node::init()) return false;
	Plant::_init();
	auto animation = Animation::create();
	animation->addSpriteFrameWithFile("Plants/PeaShooter/1.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/2.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/3.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/4.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/5.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/6.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/7.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/8.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/9.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/10.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/11.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/12.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/13.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/14.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/15.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/16.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/17.png");
	animation->addSpriteFrameWithFile("Plants/PeaShooter/18.png");
	//animation->addSpriteFrameWithFile("Plants/PeaShooter/13.png");
	animation->setDelayPerUnit(0.08f);
	auto animate = Animate::create(animation);
	m_body = Sprite::create("Plants/PeaShooter/1.png");
	m_body->runAction(RepeatForever::create(animate));
	m_body->setScale(0.2f);
	//m_body->setScaleY(0.2f);
	this->addChild(m_body);
	m_body->setAnchorPoint(Vec2(0.05, 0.2));
	interval = 1.4f;
	health = 300;
	srand(time(0));
	schedule(CC_CALLBACK_1(Peashooter::shot, this), interval, "Shot");
	schedule(CC_CALLBACK_1(Plant::bulletChecker, this), 1.0f, "Checker");
	return true;
}

void Peashooter::shot(float dt) {
	if (!haveZombieInArea) return;
	if (m_space) {
		Bullets* pea;
		if (rand() < 10600) pea = FirePea::create();
		else pea = Pea::create();
		pea->setPosition(getPositionX() + 64, getPositionY() + 80);
		pea->setLine(this->line);
		pea -> runAction(MoveBy::create(4, Vec2(1536, 0)));
		m_space->addChild(pea);
		bullets.pushBack(pea);
	}
}