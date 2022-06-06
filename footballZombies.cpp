#include "footballZombies.h"

bool footballZombies::init() {
	if (!Node::init()) return false;
	Zombie::_init();
	speed = 60;
	realspeed = speed;
	health = maxHealth = 2400;
	Attack = 200;
	type = 4;
	//type = ZombiesType::CommonZombies;
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithFile("Zombies/footballZombies/1.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/2.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/3.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/4.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/5.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/6.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/7.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/8.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/9.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/10.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/11.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/12.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/13.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/14.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/15.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/16.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/17.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/18.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/19.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/20.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/21.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/22.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/23.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/24.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/25.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/26.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/27.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/28.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/29.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/30.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/31.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/32.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/33.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/34.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/35.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/36.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/37.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/38.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/39.png");
	animation->addSpriteFrameWithFile("Zombies/footballZombies/40.png");
	animation->setDelayPerUnit(0.07f);
	auto animate = Animate::create(animation);
	m_body = Sprite::create("Zombies/footballZombies/1.png");
	m_body->setScale(0.29f);
	m_body->setAnchorPoint(Vec2(0.25, 0));
	m_body->runAction(RepeatForever::create(animate));
	bloodBar->setPosition(m_body->getPosition() + Vec2(96, 0));
	this->addChild(m_body);
	this->addChild(bloodBar);
	schedule(CC_CALLBACK_1(Zombie::checkStatus, this), 0.1f, "CheckStatus");
	scheduleUpdate();
	return true;
}

void footballZombies::setType(int __type) {
	this->type = type;
}

int footballZombies::getType() {
	return this->type;
}