#include "Snowpea.h"

bool SnowPea::init() {
	if (!Node::init()) return false;
	m_body = Sprite::create("Plants/Snowpea.png");
	this->addChild(m_body);
	m_body->setAnchorPoint(Vec2(0.0, 0.0));
	attack = 20;
	type = 2;
	//schedule(CC_CALLBACK_1(Bullets::updatePosition, this), 0.0533, "updblt");
	this->status = true;
	return true;
}

int SnowPea::attackZombie(Zombie* zombie) {
	if (this == nullptr) return 0;
	if (this == (Bullets*)0xdddddddd) return 0;
	if (this->m_body == (Sprite*)0xdddddddd) return 0;
	if (this->status > 1) return 0;
	if (this->m_body == nullptr) return 0;

	if (this->getPositionX() - zombie->getPositionX() > 25 && this->getPositionX() - zombie->getPositionX() < 128) {
		zombie->health -= this->attack;
		if (zombie->health < zombie->maxHealth * 0.2 && this->type == 4) zombie->health -= 20.0;
		zombie->flash();
		zombie->setSlowDown();
		if (this->buff) zombie->setFroze();
		this->removeFromParent();
		this->status = false;
		return 1;
	}
	return 0;
}