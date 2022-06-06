#pragma once
#include "Zombie.h"

class BucketZombies : public Zombie {
public:
	virtual bool init();
	CREATE_FUNC(BucketZombies);
	virtual void setType(int);
	virtual int getType();
};