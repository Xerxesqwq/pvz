#pragma once
#include "Zombie.h"

class footballZombies : public Zombie {
public:
	virtual bool init();
	CREATE_FUNC(footballZombies);
	virtual void setType(int);
	virtual int getType();
};