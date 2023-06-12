#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "CommonUtil.h"

#pragma warning(disable: 26429)
#pragma warning(disable: 26440)

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

    return true;
}

