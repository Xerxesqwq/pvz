#include "mainGameNight.h"

USING_NS_CC;

Scene* mainGameNight::createScene()
{
	return mainGameNight::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in mainGameNightScene.cpp\n");
}

// on "init" you need to initialize your instance
//Card* cardListener;

void mainGameNight::createPlant(int type, int x, int y) {
	if (x > 5 || y > 9) return;
	if (type == 1) plant = Peashooter::create();
	else if (type == 2) plant = SunFlower::create();
	else if (type == 3) plant = SnowPeaShooter::create();
	else if (type == 4) plant = DoublePeaShooter::create();
	else if (type == 5) plant = NutWall::create();
	else return;
	plant->setType(type);
	card[1]->getGirdStatus(0, x - 1, y - 1);
	plant->setSpace(plantLayer);
	plant->setAnchorPoint(Vec2(0, 0));
	plant->setSpace(plantLayer);
	plant->setPosition(Vec2(128 * (y - 1), 128 * (x - 1)));
	plant->setLine(x);
	plant->setCol(y);
	plantLayer->addChild(plant);
	plants.pushBack(plant);
	//log("wlsyyds");
	//plants.insert(plant);
}

void mainGameNight::createZombie(int type, int x, int y = 1080) {
	if (type == 1) zombie = CommonZombies::create();
	else if (type == 2) zombie = ConeZombies::create();
	else if (type == 3) zombie = BucketZombies::create();
	else if (type == 4) zombie = footballZombies::create();
	else return;
	//zombie->setType(1);
	zombie->setAnchorPoint(Vec2(0, 0));
	zombie->setPosition(Vec2(y, (x - 1) * 128));
	zombie->setLine(x);
	zombie->setRoundBelongs(zombiesGen->getPassedRound());
	this->addChild(zombie, 3);
	zombies.pushBack(zombie);
	//zombies.insert(zombie);
}
bool mainGameNight::init()
{
	srand(time(0));
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto pauseItem = MenuItemImage::create(
		"Scence/pause.png",
		"Scence/pause.png",
		CC_CALLBACK_1(mainGameNight::menuCloseCallback, this));


	if (pauseItem == nullptr ||
		pauseItem->getContentSize().width <= 0 ||
		pauseItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		pauseItem->setScale(0.3);
		pauseItem->setAnchorPoint(Vec2(0, 0));
		float x = 1240;
		float y = origin.y;
		pauseItem->setPosition(Vec2(x, y));
	}

	auto homeItem = MenuItemImage::create(
		"Scence/home.png",
		"Scence/home.png",
		CC_CALLBACK_1(mainGameNight::backHome, this));

	homeItem->setScale(0.3);
	homeItem->setAnchorPoint(Vec2(0, 0));
	homeItem->setPosition(Vec2(1200, 0));


	auto musicItem = MenuItemImage::create(
		"Scence/sound.png",
		"Scence/sound.png",
		CC_CALLBACK_1(mainGameNight::pauseSound, this));

	musicItem->setScale(0.3);
	musicItem->setAnchorPoint(Vec2(0, 0));
	musicItem->setPosition(Vec2(1160, 0));


	// create menu, it's an autorelease object
	auto menu = Menu::create(pauseItem, NULL);
	menu->setPosition(Vec2::ZERO);
	auto homeMenu = Menu::create(homeItem, NULL);
	homeMenu->setPosition(Vec2::ZERO);
	auto soundMemu = Menu::create(musicItem, NULL);
	soundMemu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);
	this->addChild(homeMenu, 5);
	this->addChild(soundMemu, 5);

	sunLabel = Label::createWithSystemFont("50", "Arial", 40);
	createBasicScene();
	sun::create()->collect(-1000200);
	//createZombie(1, 1);
	zombiesGen->setRoundCount(zombiesGen->setRoundCount(0));

	return true;
}


void mainGameNight::createBasicScene() {
	/*Sprite* gird[5][9];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if ((i + j) & 1) gird[i][j] = Sprite::create("scence/grass1.png");
			else gird[i][j] = Sprite::create("scence/grass2.png");
			gird[i][j]->setAnchorPoint(Vec2(0, 0));
			gird[i][j]->setPosition(Vec2(128 * j, 128 * i));
			this->addChild(gird[i][j], 0);
		}
	}*/
	backGround = Sprite::create("Scence/Background2.png");
	backGround->setAnchorPoint(Vec2(0, 0));
	backGround->setPosition(-360, -50);
	backGround->setScaleX(3.00f);
	backGround->setScaleY(2.5f);
	this->addChild(backGround, 0);
	sunLabel->setColor(Color3B(192, 32, 32));
	sunLabel->setPosition(Vec2(64, 664));
	this->addChild(sunLabel, 1);

	Sprite* staticSun = Sprite::create("Scence/staticSun.png");
	staticSun->setPosition(Vec2(64, 728));

	this->addChild(staticSun);
	backGroundAudio = SimpleAudioEngine::getInstance();
	backGroundAudio->playBackgroundMusic("Music/mainMusic1.mp3", true);


	//zombiesGen._init();
	zombiesGen = zombiesGenerator::create();
	this->addChild(zombiesGen, 0);


	plantLayer = Layer::create();
	this->addChild(plantLayer, 3);
	schedule(CC_CALLBACK_1(mainGameNight::check, this), 0.07f, "check");
	schedule(CC_CALLBACK_1(mainGameNight::checkPlantisEaten, this), 0.06f, "checkeat");
	schedule(CC_CALLBACK_1(mainGameNight::updateSun, this), 0.15f, "chksun");
	schedule(CC_CALLBACK_1(mainGameNight::updatePlantsAttack, this), 0.4f, "updateAttack");
	schedule(CC_CALLBACK_1(mainGameNight::plantEventListener, this), 0.05f, "plantListener");
	schedule(CC_CALLBACK_1(mainGameNight::updateCardWithSun, this), 0.05f, "updcrdcst");
	schedule(CC_CALLBACK_1(mainGameNight::Gen, this), 0.1f, "zbgen");
	schedule(CC_CALLBACK_1(mainGameNight::checkWin, this), 1.0f, "ckw");

	card[0] = peaShooterCard::create();
	card[0]->setAnchorPoint(Vec2(0, 0));
	card[0]->setPosition(Vec2(192, 704));
	card[0]->setSpace(plantLayer);
	this->addChild(card[0], 2);
	card[1] = sunFlowerCard::create();
	card[1]->setSpace(plantLayer);
	card[1]->setAnchorPoint(Vec2(0, 0));
	card[1]->setPosition(Vec2(320, 704));
	this->addChild(card[1], 2);

	card[2] = nutWallCard::create();
	card[2]->setSpace(plantLayer);
	card[2]->setAnchorPoint(Vec2(0, 0));
	card[2]->setPosition(Vec2(448, 704));
	this->addChild(card[2], 2);

	card[3] = snowPeaShooterCard::create();
	card[3]->setSpace(plantLayer);
	card[3]->setAnchorPoint(Vec2(0, 0));
	card[3]->setPosition(Vec2(576, 704));
	this->addChild(card[3], 2);

	card[4] = doublePeaShooterCard::create();
	card[4]->setSpace(plantLayer);
	card[4]->setAnchorPoint(Vec2(0, 0));
	card[4]->setPosition(Vec2(704, 704));
	this->addChild(card[4], 2);

	card[5] = shovel::create();
	card[5]->setSpace(plantLayer);
	card[5]->setAnchorPoint(Vec2(0, 0));
	card[5]->setPosition(card[4]->getPosition() + Vec2(512, 16));
	this->addChild(card[5]);
	//gameWin();
	//gameLose();
	levelBar = LoadingBar::create("Scence/levelBar.png");
	Sprite* levelBarBackGround = Sprite::create("Scence/levelBarBackGround.png");
	levelBarBackGround->setPosition(Vec2(960, 12));
	this->addChild(levelBarBackGround, 5);
	levelBar->setPosition(Vec2(960, 12));
	levelBar->setPercent(0);
	sun::create()->collect(1000150);
	this->addChild(levelBar, 5);

	Card* tmp = peaShooterCard::create();
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
			tmp->getGirdStatus(2, i, j);

}

void mainGameNight::Gen(float dt) {
	int cnt = 0;
	//log("queuesize : %d\n", zombiesGen.zombieQueue.size());
	if (!zombiesGen->getThisRoundStatus()) return;
	for (auto& x : zombiesGen->zombieQueue) {
		int _typ = x;
		createZombie(_typ, rand() % 5 + 1, 1200 + rand() % 120);
		cnt++;
	}
	if (cnt) {
		zombiesGen->setThisRoundStatus(false);
		levelBar->setPercent(100.0 * zombiesGen->getPassedRound() / zombiesGen->setRoundCount(0));
	}
}

void mainGameNight::checkWin(float dt) {
	if (zombiesGen->getPassedRound() != zombiesGen->setRoundCount(0)) return;
	int sum = 0;
	for (auto& zombie : zombies) {
		if (zombie == nullptr) continue;
		if (zombie->health <= 0) continue;
		sum += zombie->health;
	}
	if (!sum) gameWin();
}

void mainGameNight::checkPlantisEaten(float dt) {
	for (auto& plant : plants) {
		if (plant == nullptr) {
			//plants.erase(plant);
			continue;
		}
		for (auto& zombie : zombies) {
			if (zombie == nullptr || zombie->die) continue;
			if (zombie->getPositionX() - plant->getPositionX() <= 64 &&
				zombie->line == plant->line && zombie->getPositionX() -
				plant->getPositionX() >= -64) {
				zombie->setPause();
				/*if (!eattingEffect) {
					eattingEffect = true;
					scheduleOnce(CC_CALLBACK_1(mainGameNight::playEattingEffect, this), 0.8f, "etefct");
				}*/
				if (zombie->health <= 0) continue;
				if (zombie->frozeStatus) continue;
				plant->health = plant->health - zombie->attackPoint * dt;
				
				if (plant->getType() == 5) {
					zombie->health -= zombie->attackPoint * dt * 2.0 / 10.0;
					zombiesGen->receiveAttack(zombie->attackPoint * dt * 0.2);

				}

				plant->flash();
				if (plant->health <= 0) {
					zombie->setNormal();
					if (zombie->slowDownStatus == true) zombie->setSlowDown();
				}
			}
		}

		if (plant->health <= 0 && plant->status) {
			plant->status = false;
			card[1]->getGirdStatus(2, plant->getLine() - 1, plant->getCol() - 1);
			plant->removeFromParent();
			//plants.erase(plant);
		}
	}
}

void mainGameNight::check(float dt) {
	for (auto& plant : plants)
		for (auto& zombie : zombies) {
			for (auto& x : plant->bullets) {
				if (zombie == nullptr) continue;
				if (zombie->health <= 0) continue;
				if (x == nullptr) continue;
				if (!x->status) continue;
				if (x->line == zombie->line) {
					int tmp = x->getAttack();
					int realAttack = x->attackZombie(zombie) * tmp;
					if (zombie->getRoundBelongs() != zombiesGen->getPassedRound()) continue;
					zombiesGen->receiveAttack(realAttack);
					//if (zombie->health <= 0) zombies.erase(zombie);
				}
			}
		}
	for (auto& zombie : zombies) {
		if (zombie->health > 0 && zombie->getPositionX() < -64.0 && !loseStatus) {
			loseStatus = 1;
			auto loseEffect = SimpleAudioEngine::getInstance();
			//eattingEffect->preloadEffect("Music/losemusic.mp3");
			loseEffect->playEffect("Music/losemusic.mp3", false, 1.0f, 1.0f, 1.0f);
			for (auto& zom : zombies) {
				if (zom == nullptr) continue;
				if (zom->health <= 0) continue;
				if (zom != zombie) zom->realspeed = 0;
				zom->runAction(MoveBy::create(1.0f, Vec2(350, 0)));
			}
			backGroundAudio->pauseBackgroundMusic();
			backGround->runAction(MoveBy::create(1.0f, Vec2(350, 0)));

			for (auto& plant : plants) {
				if (plant == nullptr) continue;
				if (plant->health <= 0) continue;
				plant->runAction(MoveBy::create(1.0f, Vec2(350, 0)));
			}


			scheduleOnce(CC_CALLBACK_1(mainGameNight::gameLose, this), 3.0f, "lose");
		}
	}
}

void mainGameNight::updateSun(float dt) {
	sun* sunListener = sun::create();
	char tmp[11]; sprintf(tmp, "%d", sunListener->collect(1));
	sunLabel->setString(std::string(tmp));
}

void mainGameNight::updatePlantsAttack(float dt) {
	for (auto& plant : plants) {
		if (plant == nullptr || plant->health <= 0) continue;
		bool status = false;
		for (auto& zombie : zombies) {
			if (zombie == nullptr || zombie->health <= 0) continue;
			status |= (plant->getPositionX() < zombie->getPositionX() - 64
				&& plant->zombieInAttackArea(zombie->getLine(), zombie->getPositionX()));
		}
		plant->setAttack(status);
	}
}

void mainGameNight::updateCardWithSun(float dt) {
	sun* sunListener = sun::create();
	int curruentSun = sunListener->collect(1);
	/*for (int i = 0; i < 8; i++) {
		card[i]->updateCostLabel(curruentSun);
	}*/
	card[1]->checkHaveEnoughSun(curruentSun);
	card[0]->checkHaveEnoughSun(curruentSun);
	card[2]->checkHaveEnoughSun(curruentSun);
	card[3]->checkHaveEnoughSun(curruentSun);
	card[4]->checkHaveEnoughSun(curruentSun);
	card[5]->checkHaveEnoughSun(25);
}

void mainGameNight::plantEventListener(float dt) {
	sun* sunListener = sun::create();
	if (card[0]->getType(0) == -1) return;
	//log("qwq: %d\n", card[0]->getType(0));
	int col = card[1]->getCol();
	int row = card[1]->getRow();
	int _typ = card[1]->getType(0);
	int _cost = card[1]->getcost(0);
	if (_typ == 99) {
		for (auto& plant : plants) {
			if (plant == nullptr || plant->health <= 0) continue;
			if (plant->getCol() == col + 1 && plant->getLine() == row + 1)
				plant->health = -1;
			card[1]->getGirdStatus(2, plant->getLine() - 1, plant->getCol() - 1);
		}
	}

	if (_typ != 99 && col < 9 && row < 5) {
		sunListener->collect(-_cost);
		createPlant(_typ, row + 1, col + 1);
	}
	for (auto& plant : plants) {
		if (plant != nullptr && plant->health > 0) {
			card[1]->getGirdStatus(0, plant->getLine() - 1, plant->getCol() - 1);
		}
	}
	card[0]->getType(-1);
}


void mainGameNight::gameLose(float dt) {
	Label* loseLabel = Label::createWithSystemFont("The Zombies Eat \n Your Brain!!!", "snap ITC", 100);
	loseLabel->setPosition(640, 300);
	loseLabel->setTextColor(Color4B(255, 0, 0, 192));
	this->addChild(loseLabel, 6);
	loseStatus = 1;
	Director::getInstance()->pause();
}

void mainGameNight::gameWin() {
	Label* loseLabel = Label::createWithSystemFont("Congratulations!!", "Impact", 100);
	loseLabel->setPosition(640, 360);
	this->addChild(loseLabel, 5);
	loseLabel->setTextColor(Color4B(255, 0, 0, 192));
	loseStatus = 2;
	auto winEffect = SimpleAudioEngine::getInstance();
	winEffect->playEffect("Music/acm_pass.wav", false, 1.0f, 1.0f, 1.0f);
	backGroundAudio->pauseBackgroundMusic();
	Director::getInstance()->pause();
	//scheduleOnce(CC_CALLBACK_1(mainGameNight::_backHome, this), 3.0f, "naftwin");
}

void mainGameNight::menuCloseCallback(Ref* pSender)
{
	//Director::getInstance()->end();
	if (loseStatus) return;
	static int pauseStatus = false;
	if (!pauseStatus) {
		Director::getInstance()->pause();
		pauseStatus = true;
	}
	else {
		Director::getInstance()->resume();
		pauseStatus = false;
	}
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void mainGameNight::backHome(Ref* pSender) {
	Director::getInstance()->popScene();
	backGroundAudio->getInstance()->pauseBackgroundMusic();
}

void mainGameNight::_backHome(float ft) {
	
	Director::getInstance()->popScene();
	backGroundAudio->getInstance()->pauseBackgroundMusic();
}

void mainGameNight::pauseSound(Ref* pSender) {
	static int status = 1;
	if (status) {
		backGroundAudio->getInstance()->pauseBackgroundMusic();
	}
	else backGroundAudio->getInstance()->resumeBackgroundMusic();
	status ^= 1;
}
