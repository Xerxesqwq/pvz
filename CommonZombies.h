#pragma once
#include "Zombie.h"

class CommonZombies : public Zombie {
public:
	virtual bool init();
	CREATE_FUNC(CommonZombies);
	virtual void setType(int);
	virtual int getType();
};