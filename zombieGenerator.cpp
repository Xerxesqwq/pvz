#include "zombieGenerator.h"
#include "global.h"

bool zombiesGenerator::init() {
	if (!Node::init())return false;
	srand(time(0));
	setHardLevel(0);
	schedule(CC_CALLBACK_1(zombiesGenerator::generateZombie, this), 0.1f, "gnrtzb");
	lastRefreshTime = clock() - 10000;
	return true;
}

void zombiesGenerator::generateZombie(float dt) {
	if (disabled) return;
	//log("refresh: %d %d %d\n", clock() - lastRefreshTime, thisRoundRefreshTime, refreshRightNow ? 1 : 0);
	if (!refreshRightNow && clock() - lastRefreshTime <= thisRoundRefreshTime) return;
	if (roundPassed >= roundCount) return;
	log("round: %d\n", this->setRoundCount(0));
	//we execute this when we decide to gemerate
	thisRoundSumHealth = 0;
	strongSum = roundPassed * hardLevel / 2 + rand() % 3 + 1;
	if (!roundPassed && hardLevel == 1) strongSum = 1;
	if (roundPassed < 5 && hardLevel != 3) strongSum = strongSum - strongSum / 3;
	if (hardLevel > 100) hardLevel = 100;
	if (hardLevel >= 5) maxStrong = 99;
	else maxStrong = roundPassed / (5 - hardLevel) + 1;
	zombieQueue.clear();
	int cur = strongSum;
	while (cur) {
		const int tmpZombie = rand() % (hardLevel > 3 ? 4 : 3) + 1;
		if (zombieStrongValue[tmpZombie] > cur
			|| zombieStrongValue[tmpZombie] > maxStrong) continue;
		zombieQueue.push_back(tmpZombie);
		cur -= zombieStrongValue[tmpZombie];
		thisRoundSumHealth += bloodValue[tmpZombie];
	}
	refreshZombieLimit = thisRoundSumHealth * (0.7 + rand() * 1.0 / 333333.0);
	thisRoundRefreshTime = 23456 + rand() % 8000;
	thisRoundReceivedAttack = 0;
	refreshRightNow = false;
	lastRefreshTime = clock();
	roundPassed++;
	thisRoundStatus = true;
	refreshSchedule = false;
#ifdef LOCAL
	printf("\nround %d : health sum: %d, limit : %d\n", roundPassed, thisRoundSumHealth, refreshZombieLimit);
#endif
}

void zombiesGenerator::refreshRightNowTrigger(float dt) {
	refreshRightNow = true;
}

void zombiesGenerator::receiveAttack(int __attack) {
	thisRoundReceivedAttack += __attack;
	//log("%d\n", thisRoundReceivedAttack);
	if (thisRoundReceivedAttack >= refreshZombieLimit && !refreshSchedule) {
		scheduleOnce(CC_CALLBACK_1(zombiesGenerator::refreshRightNowTrigger, this), 2.5f + rand() / 30000.0, "rfrstg");
		refreshSchedule = true;
	}
}

void zombiesGenerator::setHardLevel(int __hardLevel = 0) {
	static int __level = 1;
	if (!__hardLevel) hardLevel = __level;
	else __level = __hardLevel;

}

int zombiesGenerator::setRoundCount(int x) {
	static int __round = 10;
	if (!x) return __round;
	else {
		__round = x;
		roundCount = x;
		return 0;
	}
}

int zombiesGenerator::getHardLevel() {
	return hardLevel;
}

void zombiesGenerator::setDisabled(bool __status) {
	disabled = __status;
}

int zombiesGenerator::getPassedRound() noexcept {
	return roundPassed;
}
