#include "shovel.h"

bool shovel::init()
{
	if (!Node::init()) return false;
	_filename = std::string("Scence/shovel.png");
	scaleRate = 1.2f;
	m_body = Sprite::create("Scence/shovelCard.png");
	m_body->setScale(1.2f);
	cost = 0;
	//m_body->setPositionY(m_body->getPositionY() - 32);
	this->addChild(m_body, 1);
	this->plantType = 99;
	auto _mouseListener = EventListenerMouse::create();
	//Card::_init();
	_mouseListener->onMouseMove = CC_CALLBACK_1(Card::onMouseMove, this);
	_mouseListener->onMouseDown = CC_CALLBACK_1(Card::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
	return true;
}