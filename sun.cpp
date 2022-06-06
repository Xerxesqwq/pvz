#include "sun.h"

bool sun::init() {
	if (!Node::init()) return false;
	auto _mouseListener = EventListenerMouse::create();
	_mouseListener ->onMouseMove = CC_CALLBACK_1(sun::onMouseMove, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
	//currentSun = 50;
	auto animation = Animation::create();
	//animation->addSpriteFrameWithFile("Plants/sun/tai1.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai2.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai3.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai4.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai5.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai6.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai7.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai8.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai9.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai10.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai11.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai12.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai13.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai14.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai15.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai16.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai17.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai18.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai19.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai20.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai21.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai22.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai23.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai24.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai25.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai26.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai27.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai28.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai29.png");
	animation->addSpriteFrameWithFile("Plants/sun/tai30.png");
	srand(time(0));
	animation->setDelayPerUnit(0.08f);
	value = 25 + 25 * (rand() & 1);
	auto animate = Animate::create(animation);
	m_body = Sprite::create();
	m_body->runAction(RepeatForever::create(animate));
	m_body->setScale(0.5f);
	this->addChild(m_body);
	this->status = 1;
	//m_body->setAnchorPoint(Vec2(0.0, 0.0));
	scheduleOnce(CC_CALLBACK_1(sun::disappear, this), 10.0f + rand() % 3, "dispa");
	return true;
}

int sun::getValue() {
	return this->value;
}

void sun::disappear(float dt = 0.0) {
	//if (!this->status) return;
	this->status = 0;
	this->removeFromParent();
}

float sun::getDist(int x = 64, int y = 704) {
	int ret = (x - this->getPositionX()) * (x - this->getPositionX());
	ret += (y - this->getPositionY()) * (y - this->getPositionY());
	return (sqrt(ret));
}

void sun::onMouseMove(Event* event) {
	if (!this->status) return;
	EventMouse* e = (EventMouse*)event;
	if (getDist(e->getCursorX(), e->getCursorY()) <= 50) {
		this->collect(0);
	}	
}

int sun::collect(int op) {
	static int currentSun = 50;
	if (op < 0 && op >= -1000000) {
		currentSun += op;
		return currentSun;
	}
	if (op < -1000000) {
		currentSun = -1000000 - op;
		return 0;
	}
	if (op > 1000000) {
		currentSun += op - 1000000;
		return 0;
	}
	if (op == 1) return currentSun;
	currentSun += this->value;
	//log("%d\n", currentSun);
	if (this->status == 0) return 0;
	float dist = getDist();
	this->stopAllActions();
	float moveTime = std::min(1.0, 1000.0 / dist);
	auto moveTo = MoveTo::create(moveTime, Vec2(64, 704));
	this->runAction(moveTo);
	scheduleOnce(CC_CALLBACK_1(sun::disappear, this), moveTime + .01, "dispaqwq");
	this->status = 0;
	return 0;
}

