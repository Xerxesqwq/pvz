#pragma once
#ifndef __mainGameNight_SCENE_H__
#define __mainGameNight_SCENE_H__

#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "Plant.h"
#include "Zombie.h"
#include "SimpleAudioEngine.h"
#include "Peashooter.h"
#include "SunFlower.h"
#include "CommonZombies.h"
#include "SnowPeaShooter.h"
#include "ConeZombies.h"
#include "DoublePeaShooter.h"
#include "BucketZombies.h"
#include "NutWall.h"
#include "peaShooterCard.h"
#include "sunFlowerCard.h"
#include "sun.h"
#include "nutWallCard.h"
#include "snowPeaShooterCard.h"
#include "doublePeaShooterCard.h"
#include "zombieGenerator.h"
#include "footballZombies.h"
#include <cstring>
#include "shovel.h"
#include "PotatoMine.h"

using namespace CocosDenshion;

class mainGameNight : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	//virtual void update(float);
	// a selector callback
	//virtual void createSun(float);
	virtual void check(float);
	void createPlant(int, int, int);
	void createZombie(int, int, int);
	void updatePlantsAttack(float);
	virtual void checkPlantisEaten(float);
	void menuCloseCallback(cocos2d::Ref* pSender);
	void createBasicScene();
	void plantEventListener(float);
	virtual void updateCardWithSun(float);
	virtual void updateSun(float);
	virtual void Gen(float);
	virtual void checkWin(float);
	void backHome(Ref* pSender);
	void _backHome(float);
	void pauseSound(Ref* pSender);
	void gameLose(float);
	void gameWin();
	SimpleAudioEngine* backGroundAudio;
	Sprite* backGround;
	LoadingBar* levelBar;
	//void showMessage(std::string);
	//bool eattingEffect = false;
	//SimpleAudioEngine* eattingEffect;
	// implement the "static create()" method manually
	CREATE_FUNC(mainGameNight);
	Vector <Zombie*> zombies;
	Vector <Plant*> plants;
	//std::unordered_set <Zombie*>zombies;
	//std::unordered_set <Plant*>plants;
	Plant* plant;
	Zombie* zombie;
	Layer* plantLayer;
	Card* card[10];
	zombiesGenerator* zombiesGen;
	int loseStatus = 0;
	Label* sunLabel;
	int level = 1;
	//int hardLevel = 1;
};

#endif // __mainGameNight_SCENE_H__
