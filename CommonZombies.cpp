#include "CommonZombies.h"

bool CommonZombies::init() {
	if (!Node::init()) return false;
	Zombie::_init();
	speed = 22 + rand() % 7;
	realspeed = speed;
	health = maxHealth =200;
	type = 1;
	//type = ZombiesType::CommonZombies;
	Animation* animation = Animation::create();
	//auto pinfo = AutoPolygon::generatePolygon("Zombies/CommonZombies/pu1.png");

	//animation->addSpriteFrame()
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu1.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu2.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu3.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu4.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu5.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu6.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu7.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu8.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu9.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu10.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu11.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu12.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu13.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu14.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu15.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu16.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu17.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu18.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu19.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu20.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu21.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu22.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu23.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu24.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu25.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu26.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu27.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu28.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu29.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu30.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu31.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu32.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu33.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu34.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu35.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu36.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu37.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu38.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu39.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu40.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu41.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu42.png");
	animation->addSpriteFrameWithFile("Zombies/CommonZombies/pu43.png");
	m_body = Sprite::create("Zombies/CommonZombies/pu1.png");
	
	animation->setDelayPerUnit(0.08f);
	auto animate = Animate::create(animation);
	m_body->setScale(0.6f);
	m_body->setAnchorPoint(Vec2(0.15, 0));
	m_body->runAction(RepeatForever::create(animate));
	bloodBar->setPosition(m_body->getPosition() + Vec2(80, 0));
	this->addChild(m_body);
	this->addChild(bloodBar);
	schedule(CC_CALLBACK_1(Zombie::checkStatus, this), 0.1f, "CheckStatus");
	scheduleUpdate();
	return true;
}

void CommonZombies::setType(int __type) {
	this->type = type;
}

int CommonZombies::getType() {
	return this->type;
}