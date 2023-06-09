#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "CommonUtil.h"

#pragma warning(disable: 26429)

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// 墙壁图片
const std::string HelloWorld::WALL_PNG = "wall.png";
// 小球图片
const std::string HelloWorld::BALL_BLUE_PNG = "ball_blue.png";
const std::string HelloWorld::BALL_RED_PNG = "ball_red.png";
// 详细图片
const std::string HelloWorld::BOX_BLUE_PNG = "box_blue.png";
const std::string HelloWorld::BOX_RED_PNG = "box_red.png";
// 角色图片
const std::string HelloWorld::PLAYER_PNG = "charater.png";


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

    // 加载图集
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("texture_packer/sprite.plist", "texture_packer/sprite.png");

    // 设置背景
    auto background = LayerColor::create(Color4B(25, 72, 148, 255));
    this->addChild(background, LAYER_INDEX_BACKGROUND);

    // 初始化游戏数据
    initData();

    // 绘制墙壁
    drawWall();

    // 绘制小球
    drawBall();

    // 绘制箱子
    drawBox();

    // 绘制角色
    drawPlayer();

    // 初始化键盘事件
    initKeyboardListener();

    return true;
}

void HelloWorld::initData() {
    // 初始化墙壁位置信息
    wallPositions.push_back(Vec2(7, 12));
    wallPositions.push_back(Vec2(8, 12));
    wallPositions.push_back(Vec2(9, 12));

    wallPositions.push_back(Vec2(7, 11));
    wallPositions.push_back(Vec2(9, 11));

    wallPositions.push_back(Vec2(7, 10));
    wallPositions.push_back(Vec2(9, 10));
    wallPositions.push_back(Vec2(10, 10));
    wallPositions.push_back(Vec2(11, 10));
    wallPositions.push_back(Vec2(12, 10));

    wallPositions.push_back(Vec2(5, 9));
    wallPositions.push_back(Vec2(6, 9));
    wallPositions.push_back(Vec2(7, 9));
    wallPositions.push_back(Vec2(12, 9));

    wallPositions.push_back(Vec2(5, 8));
    wallPositions.push_back(Vec2(10, 8));
    wallPositions.push_back(Vec2(11, 8));
    wallPositions.push_back(Vec2(12, 8));

    wallPositions.push_back(Vec2(5, 7));
    wallPositions.push_back(Vec2(6, 7));
    wallPositions.push_back(Vec2(7, 7));
    wallPositions.push_back(Vec2(8, 7));
    wallPositions.push_back(Vec2(10, 7));

    wallPositions.push_back(Vec2(8, 6));
    wallPositions.push_back(Vec2(10, 6));

    wallPositions.push_back(Vec2(8, 5));
    wallPositions.push_back(Vec2(9, 5));
    wallPositions.push_back(Vec2(10, 5));

    // 初始化小球位置信息
    ballPositions.push_back(Vec2(8, 11));
    ballPositions.push_back(Vec2(11, 9));
    ballPositions.push_back(Vec2(6, 8));
    ballPositions.push_back(Vec2(9, 6));

    // 初始化箱子位置信息
    boxPositions.push_back(Vec2(8, 9));
    boxPositions.push_back(Vec2(10, 9));
    boxPositions.push_back(Vec2(8, 8));
    boxPositions.push_back(Vec2(9, 7));

    // 初始化角色位置信息
    playerPosition.x = 9;
    playerPosition.y = 8;
}

// 绘制 sprite
void HelloWorld::drawSprite(std::vector<Vec2> positions, std::string png, int layerIndex)
{
    for (const Vec2 wallData : positions)
    {
        auto sprite = Sprite::createWithSpriteFrameName(png);
        sprite->setContentSize(Size(CELL_SIZE, CELL_SIZE));
        sprite->setPosition(Vec2(CELL_SIZE * wallData.x, CELL_SIZE * wallData.y));
        this->addChild(sprite, layerIndex);
    }
}

// 绘制墙壁
void HelloWorld::drawWall()
{
    drawSprite(wallPositions, HelloWorld::WALL_PNG, LAYER_INDEX_WALL);
}

// 绘制小球
void HelloWorld::drawBall()
{
    drawSprite(ballPositions, BALL_BLUE_PNG, LAYER_INDEX_BALL);
}

// 绘制箱子
void HelloWorld::drawBox()
{
    drawSprite(boxPositions, BOX_BLUE_PNG, LAYER_INDEX_BOX);
}

// 绘制角色
void HelloWorld::drawPlayer()
{
    player = Sprite::createWithSpriteFrameName(PLAYER_PNG);
    player->setContentSize(Size(CELL_SIZE, CELL_SIZE));
    player->setPosition(Vec2(CELL_SIZE * playerPosition.x, CELL_SIZE * playerPosition.y));
    this->addChild(player, LAYER_INDEX_PLAYER);
}


// 初始化键盘事件
void HelloWorld::initKeyboardListener()
{
    auto listener = EventListenerKeyboard::create();
    listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event* e)
    {
        switch (keyCode)
        {
        case EventKeyboard::KeyCode::KEY_UP_ARROW: {
            log("key released up");
            playerMove(Vec2(0, 1));
            break;
        }
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW: {
            log("key released right");
            playerMove(Vec2(1, 0));
            break;
        }
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW: {
            log("key released down");
            playerMove(Vec2(0, -1));
            break;
        }
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW: {
            log("key released left");
            playerMove(Vec2(-1, 0));
            break;
        }
        }
        return true;
    };

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, player);
}

void HelloWorld::playerMove(Vec2 dirVector)
{
    // 更新角色位置信息
    playerPosition.x += dirVector.x;
    playerPosition.y += dirVector.y;

    // 移动角色
    const auto x = player->getPosition().x + CELL_SIZE * dirVector.x;
    const auto y = player->getPosition().y + CELL_SIZE * dirVector.y;
    player->setPosition(x,y);
}
