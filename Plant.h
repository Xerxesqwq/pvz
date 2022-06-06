#pragma once
#include "cocos2d.h"
#include "Bullets.h"
#include "Zombie.h"
#include <unordered_set>

USING_NS_CC;

class Plant : public Node {
public:
	void bulletChecker(float);
	void _init();
	void setSpace(Layer*);
	bool status = true;
	int lastFlashTime = 0;
	float interval;
	int health;
	int line, col, buff = false;
	int getType();
	void setType(int);
	virtual void shot(float);
	void setLine(int __line) { this->line = __line; };
	void setCol(int __col) { this->col = __col; };
	int getLine() { return line; };
	int getCol() { return col; };
	void setAttack(bool);
	void flash();
	void recoverColor(float);
	bool zombieInAttackArea(int, int);
	Vector <Bullets*> bullets;
	MoveBy* bulletMove;
	//std:: unordered_set <Bullets*> bullets;
protected:
	bool haveZombieInArea;
	int type;
	Sprite* m_body;
	Layer* m_space;
};