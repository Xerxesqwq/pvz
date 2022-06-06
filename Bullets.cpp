#include "Bullets.h"

int Bullets::attackZombie(Zombie *zombie) {
	return 0;
}
 
void Bullets::updatePosition(float dt) {
	float curx = getPositionX();
	curx += dt * 384.0f;
	setPositionX(curx);
	if (curx > 1400) this->removeFromParent();
}

int Bullets::getAttack() {
	return attack;
}