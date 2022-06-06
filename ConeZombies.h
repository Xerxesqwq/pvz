#pragma once
#include "Zombie.h"

class ConeZombies : public Zombie {
public:
	virtual bool init();
	CREATE_FUNC(ConeZombies);
	virtual void setType(int);
	virtual int getType();
};