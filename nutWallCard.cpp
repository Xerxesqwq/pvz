#include "nutWallCard.h"

bool nutWallCard::init()
{
	if (!Node::init()) return false;
	_filename = std::string("Plants/NutWall/jian1.png");
	scaleRate = 1.2;
	coolDownTime = 30.0;
	m_body = Sprite::create(_filename);
	m_body->setScale(0.88f);
	m_body->setPositionY(m_body->getPositionY() + 16);
	this->addChild(m_body, 1);
	costLabel = Label::createWithSystemFont("100", "Arial", 26);
	this->addChild(costLabel, 1);
	costLabel->setPositionY(costLabel->getPositionY() - 48);
	costLabel->setPositionX(costLabel->getPositionX() - 8);
	costLabel->setColor(Color3B(0, 0, 0));
	backGround = Sprite::create("Scence/cardSlot1.png");
	backGround->setScale(0.8);
	coolDownMask = Sprite::create("Scence/coolDownMask.png");
	coolDownMask->setScale(0.8);
	this->addChild(coolDownMask, 2);
	coolDownMask->setPositionY(128);
	this->addChild(backGround, 0);
	this->setCost(100);
	this->plantType = 5;
	auto _mouseListener = EventListenerMouse::create();
	Card::_init();
	_mouseListener->onMouseMove = CC_CALLBACK_1(Card::onMouseMove, this);
	_mouseListener->onMouseDown = CC_CALLBACK_1(Card::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
	return true;
}
