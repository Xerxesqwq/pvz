#include "SunFlower.h"

void SunFlower::produceSun(float dt) {
	if (m_space != nullptr) {
		auto Sun = sun::create();
		Sun->setPosition(Vec2(this->getPositionX() - rand() % 32,
			this->getPositionY() - rand() % 32));
		m_space->addChild(Sun, 3);
		auto jump = JumpBy::create(0.5, Vec2(rand() % 64 + 16, rand() % 64), 64, 1);
		Sun->runAction(jump);
	}
	return;
	//auto sun = Sun::create();
}

bool SunFlower::init() {
	if (!Node::init()) return false;
	auto animation = Animation::create();
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang1.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang2.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang3.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang4.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang5.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang6.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang7.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang8.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang9.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang10.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang11.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang12.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang13.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang14.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang15.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang16.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang17.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang18.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang19.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang20.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang21.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang22.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang23.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang24.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang25.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang26.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang27.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang28.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang29.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang30.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang31.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang32.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang33.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang34.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang35.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang36.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang37.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang38.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang39.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang40.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang41.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang42.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang43.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang44.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang45.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang46.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang47.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang48.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang49.png");
	animation->addSpriteFrameWithFile("Plants/SunFlower/xiang50.png");
	animation->setDelayPerUnit(0.08f);
	auto animate = Animate::create(animation);
	m_body = Sprite::create("Plants/SunFlower/xiang1.png");
	m_body->runAction(RepeatForever::create(animate));
	m_body->setScale(0.4f);
	this->addChild(m_body);
	m_body->setAnchorPoint(Vec2(0.0, 0.0));
	//interval = 1.4f;
	health = 300;
	schedule(CC_CALLBACK_1(SunFlower::produceSun, this), 24.0, "sun1");
	scheduleOnce(CC_CALLBACK_1(SunFlower::produceSun, this), 6 + rand() % 3, "sun2");
	//schedule(CC_CALLBACK_1(Plant::bulletChecker, this), 1.0f, "Checker");
	return true;
}