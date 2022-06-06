#include "DoublePeaShooter.h"

bool DoublePeaShooter::init() {
	if (!Node::init()) return false;
	Plant::_init();
	auto animation = Animation::create();
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou1.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou2.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou3.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou4.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou5.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou6.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou7.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou8.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou9.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou10.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou11.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou12.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou13.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou14.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou15.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou16.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou17.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou18.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou19.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou20.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou21.png");
	animation->addSpriteFrameWithFile("Plants/DoublePeaShooter/tou22.png");
	animation->setDelayPerUnit(0.07f);
	auto animate = Animate::create(animation);
	m_body = Sprite::create("Plants/DoublePeaShooter/tou1.png");
	m_body->runAction(RepeatForever::create(animate));
	m_body->setScale(0.7f);
	this->addChild(m_body);
	m_body->setAnchorPoint(Vec2(0.2, 0.2));
	interval = 1.4f;
	health = 300;
	srand(time(0));
	schedule(CC_CALLBACK_1(DoublePeaShooter::shot, this), interval, "Shot");
	schedule(CC_CALLBACK_1(Plant::bulletChecker, this), 1.0f, "Checker");
	return true;
}

void DoublePeaShooter::shot(float dt) {
	if (!haveZombieInArea) return;
	for (int i = 0; i < 2; i++) {
		if (m_space) {
			Bullets* pea;
			int tmp = rand();
			if (tmp < 2000) pea = GhostFirePea::create();
			else if (tmp < 5000) pea = FirePea::create();
			else if (tmp < 10000) pea = SnowPea::create();
			else pea = Pea::create();
			pea->setPosition(getPositionX() + 16 + i * 48, getPositionY() + 80);
			pea->setLine(this->line);
			pea->runAction(MoveBy::create(4, Vec2(1536, 0)));
			m_space->addChild(pea);
			bullets.pushBack(pea);
		}
	}
}