#pragma once
#include "Plant.h"
#include "pea.h"
#include "Firepea.h"
#include "Snowpea.h"
#include "GhostFirepea.h"

class DoublePeaShooter : public Plant {
public:
	virtual bool init();
	virtual void shot(float);
	CREATE_FUNC(DoublePeaShooter);
};