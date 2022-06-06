#pragma once

#include "cocos2d.h"
#include "Zombie.h"

USING_NS_CC;

class Bullets : public Node {
public:
	//virtual bool init();
	//CREATE_FUNC(Pea);
	//int getAttack();
	virtual int attackZombie(Zombie*);
	virtual void updatePosition(float);
	int getAttack();
	bool status, buff = false;
	int line, type;
	void setLine(int __line) { this->line = __line; };
protected:
	Sprite* m_body;
	int attack;
};