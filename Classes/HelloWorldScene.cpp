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

	auto titleLabel = Label::createWithTTF(CommonUtil::GBKToUTF8("推箱子"), CommonUtil::GetDefaultFontPath(), 24);
	const auto x = visibleSize.width / 2;
	const auto y = origin.y + visibleSize.height - titleLabel->getContentSize().height;
	titleLabel->setPosition(Vec2(x, y));
	this->addChild(titleLabel, 1);

	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);
}

