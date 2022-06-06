#include "Zombie.h"

void Zombie::checkStatus(float dt) {
	if (clock() - lastSlownDown > 10000 && this -> slowDownStatus == true) {
		this->setNormal();
		this-> slowDownStatus = false;
		this->m_body->setColor(Color3B(255, 255, 255));
		this->attackPoint = 100;
	}
	if (this->health <= 0) {
		this->removeFromParent();
		this->die = true;
	}
	if (clock() - lastFrozeTime >= 5000) this->frozeStatus = false;
	
}

void Zombie::update(float dt) {
	
	float curx = getPositionX();
	float cury = getPositionY();
	curx -= dt * realspeed;
	//if (health + (health << 1) < maxHealth)
	//	bloodBar->setColor(Color3B(192, 255, 0));
	if(health != maxHealth)
		bloodBar->setPercent(health * 100.0 / maxHealth);
	if (this->frozeStatus) return;
	setPosition(Vec2(curx, cury));
	//log("zombie pos: %f\n", this -> getPositionX());
	//if (clock() - lastEatting >= 66) this->realspeed =
	//	slowDownStatus ? speed / 2 : speed;
	//if (curx < -64) log("You lose the game");
}

void Zombie::setPause() {
	this->realspeed = 0;
}

void Zombie::setRoundBelongs(int __round) {
	roundBelongs = __round;
}

void Zombie::setFroze() {
	this->frozeStatus = true;
	lastFrozeTime = clock();
}

int Zombie::getRoundBelongs() {
	return roundBelongs;
}

void Zombie::setNormal() {
	//this->frozeStatus = false;
	this->m_body->setColor(Color3B(255, 255, 255));
	this->realspeed = speed;
	this->attackPoint = Attack;
}

int Zombie::getLine() {
	return line;
}

void Zombie::_init() {
	bloodBar = LoadingBar::create("Scence/loadingBar.png");
	//bloodBar->setColor(Color3B(0, 192, 0));
	//bloodBar->setPercent(100.0f);
}

void Zombie::flash() {
	if (clock() - lastFlashTime < 500.0) return;
	if (this->slowDownStatus)
		this->m_body->setColor(Color3B(0, 0, 255));
	else this->m_body->setColor(Color3B(200, 200, 200));
	scheduleOnce(CC_CALLBACK_1(Zombie::recoverColor, this), 0.25f, "qwqqaqwq");
	lastFlashTime = clock();
}

void Zombie::recoverColor(float dt) {
	if(this->slowDownStatus) this->m_body->setColor(Color3B(0, 96, 216));
	else this->m_body->setColor(Color3B(255, 255, 255));
}
 
void Zombie::setSlowDown() {
	//log("%d\n", this->realspeed);
	this->m_body->setColor(Color3B(0, 96, 216));
	this->lastSlownDown = clock();
	if (slowDownStatus == false) {
		this->attackPoint = Attack / 2;
		this->realspeed = this->speed / 2;
	}
	slowDownStatus = true;
}