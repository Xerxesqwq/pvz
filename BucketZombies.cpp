#include "BucketZombies.h"

bool BucketZombies::init() {
	if (!Node::init()) return false;
	Zombie::_init();
	speed = 22 + rand() % 7;
	realspeed = speed;
	health = maxHealth = 1300;
	type = 3;
	//type = ZombiesType::CommonZombies;
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong1.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong2.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong3.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong4.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong5.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong6.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong7.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong8.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong9.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong10.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong11.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong12.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong13.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong14.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong15.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong16.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong17.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong18.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong19.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong20.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong21.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong22.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong23.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong24.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong25.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong26.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong27.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong28.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong29.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong30.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong31.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong32.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong33.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong34.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong35.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong36.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong37.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong38.png");
	animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong39.png");
	//animation->addSpriteFrameWithFile("Zombies/BucketZombies/tong40.png");
	animation->setDelayPerUnit(0.08f);
	auto animate = Animate::create(animation);
	m_body = Sprite::create("Zombies/BucketZombies/tong1.png");
	m_body->setScale(0.6f);
	m_body->setAnchorPoint(Vec2(0.12, 0));
	m_body->runAction(RepeatForever::create(animate));
	bloodBar->setPosition(m_body->getPosition() + Vec2(96, 0));
	this->addChild(m_body);
	this->addChild(bloodBar);
	schedule(CC_CALLBACK_1(Zombie::checkStatus, this), 0.1f, "CheckStatus");
	scheduleUpdate();
	return true;
}

void BucketZombies::setType(int __type) {
	this->type = type;
}

int BucketZombies::getType() {
	return this->type;
}