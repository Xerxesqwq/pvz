#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "cocos2d.h"

USING_NS_CC;

static class zombiesGenerator : public Node {
public:
	void generateZombie(float);
	void receiveAttack(int attackValue);
	void setHardLevel(int);
	bool getThisRoundStatus() { return thisRoundStatus; }
	void setThisRoundStatus(bool __st) { thisRoundStatus = __st; }
	void refreshRightNowTrigger(float);
	int getHardLevel();
	int getPassedRound() noexcept;
	int refreshZombieLimit;
	std::vector <int> zombieQueue;
	CREATE_FUNC(zombiesGenerator);
	virtual bool init();
	void setDisabled(bool);
	int setRoundCount(int);
private:
	int lastRefreshTime = 0;
	bool thisRoundStatus;
	bool disabled = false;
	bool refreshRightNow; // if the zombies this round die quickly
	bool refreshSchedule = false;// we need to refresh zombies right now(dealy for a short time)
	int thisRoundSumHealth;
	int thisRoundReceivedAttack = 0;
	int thisRoundRefreshTime = 30000;
	// left health for this round, if it below than 1+(*) / 2 * sumHealth,
	//we will prepare to refresh right now.
	int roundPassed;
	//The Passed rounds
	int strongSum;
	//the sum of strong value for zombies this round, as the round passed increase
	//this will increase
	int maxStrong;
	//the max strong value of zombies generated this round, at the beginning of game,
	//we usually don't want to generate zombie that is hard to deal with.
	int hardLevel = 4;
	int roundCount = 10;
	//the hard level, default is 1(easy), medium : 2, hard: other
	const int zombieStrongValue[5] = { 0, 1, 2, 4, 10 };
	const int bloodValue[5] = { 0, 200, 560, 1300, 3000 };
};