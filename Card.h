#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Card : public Node {
public:
	// CREATE_FUNC(Pea);
	bool coolDownStatus();
	virtual void setCost(int);
	int getType(int);
	int getRow();
	int getCol();
	int getcost(int);
	void setSpace(Layer*);
	bool onMouse();
	void onMouseMove(Event*);
	void onMouseDown(Event*);
	void reCoolDown();
	void plantAction();
	bool getGirdStatus(int, int, int);
	virtual void _init();
	void updateCostLabel(float);
	virtual void checkHaveEnoughSun(const int);
protected:
	Layer* m_space;
	Sprite* m_body;
	Sprite* plantTmp;
	Label* costLabel;
	Sprite* backGround;
	Sprite* coolDownMask;
	bool onMouseStatus = false;
	bool haveEnoughSun = false;
	int cost, plantType;
	int currentCol, currentRow;
	float coolDownTime = 7.5f;//seconds
	float scaleRate = 1.0;
	int lastPlantTime = -998244353;
	int status = 0; 
	std:: string _filename;
	//default value is 0
	//it will become 1 when we choose the card and prepare to plant it
	//after we plant it become to 0 again
};