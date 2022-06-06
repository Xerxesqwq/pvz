#include "Plant.h"

void Plant::setSpace(Layer* space) {
	m_space = space;
}

void Plant::_init() {
	haveZombieInArea = false;
}

void Plant::bulletChecker(float dt) {
	return;
	//log("%d\n", peas.size());
	for (auto &x : bullets) {
	//	if (x == nullptr) bullets.erase(x);
	}
}

int Plant::getType() {
	return type;
}

void Plant::setType(int __typ) {
	this->type = __typ;
}

void Plant::shot(float)
{
}

void Plant::flash() {
	if (clock() - lastFlashTime < 500.0) return;
	this->m_body->setColor(Color3B(200, 200, 200));
	scheduleOnce(CC_CALLBACK_1(Plant::recoverColor, this), 0.25f, "qwqqwq");
	lastFlashTime = clock();
}

void Plant::recoverColor(float dt) {
	this->m_body->setColor(Color3B(255, 255, 255));
}

bool Plant::zombieInAttackArea(int __line, int zombiePosX) {
	return __line == this->line;
}

void Plant::setAttack(bool status) {
	haveZombieInArea = status;
	if (status == false) bullets.clear();
}