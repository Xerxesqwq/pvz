#pragma once
#include "Plant.h"

class PotatoMine : public Plant {
public:
	virtual bool init();
	virtual void prepareDone(float);
	CREATE_FUNC(PotatoMine);
	Animation* animation;
};