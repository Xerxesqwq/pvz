#pragma once
#include "Bullets.h"

USING_NS_CC;

class GhostFirePea : public Bullets {
public:
	virtual bool init();
	virtual int attackZombie(Zombie*);
	CREATE_FUNC(GhostFirePea);
};