#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

enum class ZombiesType
{
	None = 0,
	CommonZombies,
	ConeZombies,
	BucketZombies,
	CommonDoorZombies,
	ConeDoorZombies,
	BucketDoorZombies,
	LmpZombies,
	CommonFlagZombies,
	ConeFlagZombies,
	BucketFlagZombies,
	CommonDoorFlagZombies,
	ConeDoorFlagZombies,
	BucketDoorFlagZombies,
	SnowZombies
};

class Zombie : public Node {
public:
	//virtual bool init();
	//CREATE_FUNC(Zombie);
	virtual void update(float);
	void checkStatus(float);
	void setPause();
	void setNormal();
	void setFroze();
	void recoverColor(float);
	void flash();
	virtual void _init();
	void setSlowDown();
	void setRoundBelongs(int);
	int getRoundBelongs();
	int getLine();
	virtual void setType(int) = 0;
	virtual int getType() = 0;
	bool die = false;
	bool slowDownStatus = false, frozeStatus = false;
	int line, speed, realspeed, type, lastFlashTime;
	int lastFrozeTime = 0;
	float health, maxHealth;
	int lastEatting;
	int attackPoint = 100;
	int Attack = 100;
	int lastSlownDown = 0;
	void setLine(int __line) { this->line = __line; };
protected:
	int roundBelongs;
	Sprite* m_body;
	LoadingBar* bloodBar;
};