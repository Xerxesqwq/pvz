#pragma once
#include "Bullets.h"

USING_NS_CC;

class Pea : public Bullets {
public:
	virtual bool init();
	CREATE_FUNC(Pea);
	virtual int attackZombie(Zombie*);
};