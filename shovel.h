#pragma once
#include "Card.h"

class shovel : public Card {
public:
	virtual bool init();
	CREATE_FUNC(shovel);
};