#pragma once
#include "cocos2d.h"

USING_NS_CC;

class sun :public Node {
public:
	virtual bool init();
	CREATE_FUNC(sun);
	//static int currentSun;
	float getDist(int, int);
	//virtual void update(float);
	//int getAttack();
	int getValue();
	int collect(int);
protected:
	Sprite* m_body;
	int value;
private:
	void onMouseMove(Event*);
	virtual void disappear(float);
	bool status;
};