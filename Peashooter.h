#pragma once
#include "Plant.h"
#include "pea.h"
#include "Firepea.h"

class Peashooter : public Plant {
public:
	virtual bool init();
	virtual void shot(float);
	CREATE_FUNC(Peashooter);
};