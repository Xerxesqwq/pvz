#pragma once
#include "Plant.h"
#include "ui/CocosGUI.h"

using namespace ui;

class NutWall : public Plant {
public:
	virtual bool init();
	//virtual void shot(float);
	CREATE_FUNC(NutWall);
	virtual void updateBlood(float);
	void recoverBlood(float);
private:
	const int maxHealth = 4000;
	LoadingBar* bloodBar;
};