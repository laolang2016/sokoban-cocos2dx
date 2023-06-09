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

// 每一格宽度宇高度
static constexpr int CELL_SIZE = 48;

// 墙壁图片
static const std::string WALL_PNG = "wall.png";

// 墙壁位置信息
static std::vector<Vec2> walls;

// 初始化地图数据
static void initData();

// 绘制墙壁
static void drawWall(HelloWorld* scene);

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

	return true;
}

static void initData() {
	// 初始化墙壁数据
	walls.push_back(Vec2(7, 12));
	walls.push_back(Vec2(8, 12));
	walls.push_back(Vec2(9, 12));

	walls.push_back(Vec2(7, 11));
	walls.push_back(Vec2(9, 11));

	walls.push_back(Vec2(7, 10));
	walls.push_back(Vec2(9, 10));
	walls.push_back(Vec2(10, 10));
	walls.push_back(Vec2(11, 10));
	walls.push_back(Vec2(12, 10));

	walls.push_back(Vec2(5, 9));
	walls.push_back(Vec2(6, 9));
	walls.push_back(Vec2(7, 9));
	walls.push_back(Vec2(12, 9));

	walls.push_back(Vec2(5, 8));
	walls.push_back(Vec2(10, 8));
	walls.push_back(Vec2(11, 8));
	walls.push_back(Vec2(12, 8));

	walls.push_back(Vec2(5, 7));
	walls.push_back(Vec2(6, 7));
	walls.push_back(Vec2(7, 7));
	walls.push_back(Vec2(8, 7));
	walls.push_back(Vec2(10, 7));

	walls.push_back(Vec2(8, 6));
	walls.push_back(Vec2(10, 6));

	walls.push_back(Vec2(8, 5));
	walls.push_back(Vec2(9, 5));
	walls.push_back(Vec2(10, 5));
}

static void drawWall(HelloWorld* scene)
{
	for (const Vec2 wallData : walls)
	{
		auto sprite = Sprite::createWithSpriteFrameName(WALL_PNG);
		sprite->setContentSize(Size(CELL_SIZE, CELL_SIZE));
		sprite->setPosition(Vec2(CELL_SIZE * wallData.x, CELL_SIZE * wallData.y));
		scene->addChild(sprite, LAYER_INDEX_WALL);
	}
}
