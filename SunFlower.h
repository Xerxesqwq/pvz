#pragma once
#include "Plant.h"
#include "Sun.h"

class SunFlower : public Plant {
public:
	virtual bool init();
	virtual void produceSun(float);
	CREATE_FUNC(SunFlower);

};