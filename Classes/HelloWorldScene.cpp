#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "CommonUtil.h"

#pragma warning(disable: 26429)

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

bool HelloWorld::init()
{
	// 先执行父类的 init
	if (!Scene::init())
	{
		return false;
	}

	// 获得可视区域大小
	const auto visibleSize = Director::getInstance()->getVisibleSize();
	log("width:%f , height:%f", visibleSize.width, visibleSize.height);
	// 获得原点位置 左下角
	const Vec2  origin = Director::getInstance()->getVisibleOrigin();
	log("x:%f , y:%f", origin.x, origin.y);

	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile("texture_packer/sprite.plist", "texture_packer/sprite.png");

	auto wall = Sprite::createWithSpriteFrameName("wall.png");
	wall->setContentSize(Size(48, 48));
	wall->setPosition(Vec2(200 + 48 * 0, 200));
	this->addChild(wall, 1);

	auto box_blue = Sprite::createWithSpriteFrameName("box_blue.png");
	box_blue->setContentSize(Size(48, 48));
	box_blue->setPosition(Vec2(200 + 48 * 1 + 1, 200));
	this->addChild(box_blue, 1);

	auto box_red = Sprite::createWithSpriteFrameName("box_red.png");
	box_red->setContentSize(Size(48, 48));
	box_red->setPosition(Vec2(200 + 48 * 2 + 2, 200));
	this->addChild(box_red, 1);

	auto ball_blue = Sprite::createWithSpriteFrameName("ball_blue.png");
	ball_blue->setContentSize(Size(48, 48));
	ball_blue->setPosition(Vec2(200 + 48 * 3 + 1, 200));
	this->addChild(ball_blue, 1);

	auto ball_red = Sprite::createWithSpriteFrameName("ball_red.png");
	ball_red->setContentSize(Size(48, 48));
	ball_red->setPosition(Vec2(200 + 48 * 3 + 1, 200));
	this->addChild(ball_red, 1);

	auto charater = Sprite::createWithSpriteFrameName("charater.png");
	charater->setContentSize(Size(48, 48));
	charater->setPosition(Vec2(200 + 48 * 4 + 1, 200));
	this->addChild(charater, 1);

	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);
}

