#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "CommonUtil.h"

#pragma warning(disable: 26429)

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// layer index
static constexpr int LAYER_INDEX_BACKGROUND = 1;
static constexpr int LAYER_INDEX_BALL = 2;
static constexpr int LAYER_INDEX_WALL = 3;
static constexpr int LAYER_INDEX_BOX = 4;
static constexpr int LAYER_INDEX_PLAYER = 5;

// 每一格宽度与高度
static constexpr int CELL_SIZE = 48;

// 墙壁图片
static const std::string WALL_PNG = "wall.png";
// 小球图片
static const std::string BALL_BLUE_PNG = "ball_blue.png";
static const std::string BALL_RED_PNG = "ball_red.png";
// 详细图片
static const std::string BOX_BLUE_PNG = "box_blue.png";
static const std::string BOX_RED_PNG = "box_red.png";
// 角色图片
static const std::string PLAYER_PNG = "charater.png";

// 墙壁位置信息
static std::vector<Vec2> wallPositions;
// 小球位置信息
static std::vector<Vec2> ballPositions;
// 箱子位置信息
static std::vector<Vec2> boxPositions;
// 角色位置信息
static Vec2 playerPosition;

// 初始化地图数据
static void initData();

/**
 * @brief 绘制精灵
 * @param scene 场景指针
 * @param positions 精灵位置列表
 * @param png 精灵图片名称
 * @param layerIndex 所在层
 */
static void drawSprite(HelloWorld* scene, std::vector<Vec2> positions, std::string png, int layerIndex);

// 绘制墙壁
static void drawWall(HelloWorld* scene);
// 绘制小球
static void drawBall(HelloWorld* scene);
// 绘制箱子
static void drawBox(HelloWorld* scene);
// 绘制角色
static void drawPlayer(HelloWorld* scene);

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
    drawWall(this);

    // 绘制小球
    drawBall(this);

    // 绘制箱子
    drawBox(this);

    // 绘制角色
    drawPlayer(this);

    return true;
}

static void initData() {
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
static void drawSprite(HelloWorld* scene, std::vector<Vec2> positions, std::string png, int layerIndex)
{
    for (const Vec2 wallData : positions)
    {
        auto sprite = Sprite::createWithSpriteFrameName(png);
        sprite->setContentSize(Size(CELL_SIZE, CELL_SIZE));
        sprite->setPosition(Vec2(CELL_SIZE * wallData.x, CELL_SIZE * wallData.y));
        scene->addChild(sprite, layerIndex);
    }
}

static void drawWall(HelloWorld* scene)
{
    drawSprite(scene, wallPositions, WALL_PNG, LAYER_INDEX_WALL);
}

// 绘制小球
static void drawBall(HelloWorld* scene)
{
    drawSprite(scene, ballPositions, BALL_BLUE_PNG, LAYER_INDEX_BALL);
}

// 绘制箱子
static void drawBox(HelloWorld* scene)
{
    drawSprite(scene, boxPositions, BOX_BLUE_PNG, LAYER_INDEX_BOX);
}

// 绘制角色
static void drawPlayer(HelloWorld* scene)
{
    auto sprite = Sprite::createWithSpriteFrameName(PLAYER_PNG);
    sprite->setContentSize(Size(CELL_SIZE, CELL_SIZE));
    sprite->setPosition(Vec2(CELL_SIZE * playerPosition.x, CELL_SIZE * playerPosition.y));
    scene->addChild(sprite, LAYER_INDEX_PLAYER);
}
