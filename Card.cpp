#include "Card.h"

void Card::setSpace(Layer *layer) {
	m_space = layer;
}

void Card::setCost(int cost) {
	this->cost = cost;
}

bool Card::onMouse() {
	return onMouseStatus;
}

void Card::checkHaveEnoughSun(const int __sun) {
	haveEnoughSun =  __sun >= cost;
}

void Card::updateCostLabel(float dt) {
	//if (this->plantType == 99) return;
	if (haveEnoughSun) costLabel->setColor(Color3B(0, 0, 0));
	else costLabel->setColor(Color3B(255, 0, 0));
}

void Card::onMouseMove(Event* event) {
	EventMouse* e = (EventMouse*)event;
	if (fabs(e->getCursorX() - this->getPositionX()) <= 64.0 &&
		fabs(e->getCursorY() - this->getPositionY()) <= 64.0) onMouseStatus = true;
	else onMouseStatus = false;
	
	currentCol = e->getCursorX() / 128;
	currentRow = e->getCursorY() / 128;
	if (this->status != 2) return;
	//if (this -> plantTmp = nullptr) return;
	plantTmp->setPosition(Vec2(e->getCursorX(), e->getCursorY()));
	//log("%d %d\n", currentRow, currentCol);

}

bool Card::coolDownStatus() {
	return clock() - lastPlantTime >= coolDownTime * 1000;
}

void Card::reCoolDown() {
	if (this->coolDownMask == nullptr) return;
	this->coolDownMask->setPositionY(0);
	auto move = MoveBy::create(coolDownTime * 1.2, Vec2(0, 148));
	coolDownMask->runAction(move);
	lastPlantTime = clock();
}

void Card::plantAction() {
	static bool havePlant[5][9];
	if (m_space != nullptr) {
		//log("%s\n", _filename.c_str());
		plantTmp = Sprite::create(_filename);
		plantTmp->setPosition(this->getPosition());
		plantTmp->setScale(scaleRate);
		m_space->addChild(plantTmp, 2);
	}
	else log("plantM_spaceISnull");
	//}
	this->status = 2;
	return;
}

int Card::getType(int __type = 0) {
	static int __plantType = -1;
	if (!__type) return __plantType;
	else __plantType = __type;
	return 0;
}

void Card::_init() {
	schedule(CC_CALLBACK_1(Card::updateCostLabel, this), 0.04f, "updcstlb");
}

bool Card::getGirdStatus(int op, int row, int col) {
	//if op = 0, then we will set the gird is used;
	//if op = 1, this will return if the gird is occupied by other plant
	//or op = 2, we remove whe plant here, or eaten
	static bool mp[5][9];
	if (op == 0) {
		mp[row][col] = true;
	}
	else if (op == 1) {
		return mp[row][col];
	}
	else if(op == 2) {
		mp[row][col] = false;
	}
	return false;
}


void Card::onMouseDown(Event* event) {
	static int globalStatus = 0;
	//log("glob = %d\n", globalStatus);
	//log("qwq, plantType = %d, %d\n", plantType, onMouseStatus * 1);
	if (!haveEnoughSun) return;
	if (onMouseStatus && coolDownStatus() && status == 0 && globalStatus == 0) {
		this->status = 1;
		globalStatus++;
		this->plantAction();
	} else if (status == 2) {
		if (onMouseStatus) {
			plantTmp->removeFromParent(); this->status = 0;
			globalStatus = 0;
			return;
		}
		else if (plantType == 99) {
			//if (!getGirdStatus(1, currentRow, currentCol)) return;
			getType(this->plantType);
			plantTmp->removeFromParent();
			this->status = 0;
			globalStatus = 0;
			return;
		}
		else if (currentRow >= 5 || currentCol >= 9 || getGirdStatus(1, currentRow, currentCol)) return;
		getcost(cost);
		getType(this->plantType);
		plantTmp->removeFromParent();
		this->status = 0;
		if(!onMouseStatus) this->reCoolDown();
		globalStatus = 0;
	}
}

int Card::getRow() {
	return currentRow;
}

int Card::getcost(int op) {
	static int _cost = 0;
	if (!op) return _cost;
	_cost = op;
}

int Card::getCol() {
	return currentCol;
}

