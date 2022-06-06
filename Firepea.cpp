#include "Firepea.h"

bool FirePea::init() {
	if (!Node::init()) return false;
	m_body = Sprite::create("Plants/Firepea.png");
	this->addChild(m_body);
	m_body->setAnchorPoint(Vec2(0.0, 0.0));
	attack = 40;
	type = 3;
	//schedule(CC_CALLBACK_1(Bullets::updatePosition, this), 0.0533, "updblt");
	this->status = true;
	return true;
}


int FirePea::attackZombie(Zombie* zombie) {
	if (this == nullptr) return 0;
	if (this == (Bullets*)0xdddddddd) return 0;
	if (this->m_body == (Sprite*)0xdddddddd) return 0;
	if (this->status > 1) return 0;
	if (this->m_body == nullptr) return 0;

	if (this->getPositionX() - zombie->getPositionX() > 25 && this->getPositionX() - zombie->getPositionX() < 128) {
		zombie->health -= this->attack;
		
		zombie->flash();
		zombie->setNormal();
		//this->m_body->removeFromParent();
		this->removeFromParent();
		this->status = false;
		return 1;
	}
	return 0;
}

