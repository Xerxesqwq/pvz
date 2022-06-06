#pragma once
#include "Plant.h"
#include "Snowpea.h"

class SnowPeaShooter : public Plant {
public:
	virtual bool init();
	virtual void shot(float);
	CREATE_FUNC(SnowPeaShooter);
};