#include "ConeZombies.h"

bool ConeZombies::init() {
	if (!Node::init()) return false;
	Zombie::_init();
	speed = 22 + rand() % 7;
	realspeed = speed;
	health = maxHealth = 560;
	type = 2;
	//type = ZombiesType::CommonZombies;
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/1.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/2.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/3.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/4.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/5.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/6.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/7.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/8.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/9.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/10.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/11.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/12.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/13.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/14.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/15.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/16.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/17.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/18.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/19.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/20.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/21.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/22.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/23.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/24.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/25.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/26.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/27.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/28.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/29.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/30.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/31.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/32.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/33.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/34.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/35.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/36.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/37.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/38.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/39.png");
	animation->addSpriteFrameWithFile("Zombies/ConeZombies/40.png");
	animation->setDelayPerUnit(0.08f);
	auto animate = Animate::create(animation);
	m_body = Sprite::create("Zombies/ConeZombies/1.png");
	m_body->setScale(0.6f);
	m_body->setAnchorPoint(Vec2(0.12, 0));
	m_body->runAction(RepeatForever::create(animate));
	bloodBar->setPosition(m_body->getPosition() + Vec2(80, 0));
	this->addChild(m_body);
	this->addChild(bloodBar);
	schedule(CC_CALLBACK_1(Zombie::checkStatus, this), 0.1f, "CheckStatus");
	scheduleUpdate();
	return true;
}

void ConeZombies::setType(int __type) {
	this->type = type;
}

int ConeZombies::getType() {
	return this->type;
}