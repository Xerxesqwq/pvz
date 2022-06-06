#pragma once
#include "cocos2d.h"
#include "mainGameDay.h"
#include "mainGameNight.h"

USING_NS_CC;

class mainInterface : public Scene {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(mainInterface);
	void DayScence(cocos2d::Ref* pSender);
	void NightScence(cocos2d::Ref* pSender);
	void setEasyMode(cocos2d::Ref* pSender);
	void setMidMode(cocos2d::Ref* pSender);
	void setMidHardMode(Ref* pSender);
	void setHardMode(Ref* Psender);
	zombiesGenerator* zomGen;
	Label* levelLabel;
};