#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
    // layer index
    static constexpr int LAYER_INDEX_BACKGROUND = 1;
    static constexpr int LAYER_INDEX_BALL = 2;
    static constexpr int LAYER_INDEX_WALL = 3;
    static constexpr int LAYER_INDEX_BOX = 4;
    static constexpr int LAYER_INDEX_PLAYER = 5;

    // 每一格宽度与高度
    static constexpr int CELL_SIZE = 48;

    // 墙壁图片
    static const std::string WALL_PNG;
    // 小球图片
    static const std::string BALL_BLUE_PNG;
    static const std::string BALL_RED_PNG;
    // 箱子图片
    static const std::string BOX_BLUE_PNG;
    static const std::string BOX_RED_PNG;
    // 角色图片
    static const std::string PLAYER_PNG;

private:
    cocos2d::Sprite * player;

private:
    // 墙壁位置信息
    std::vector<Vec2> wallPositions;
    // 小球位置信息
    std::vector<Vec2> ballPositions;
    // 箱子位置信息
    std::vector<Vec2> boxPositions;
    // 角色位置信息
    Vec2 playerPosition;

    // 初始化地图数据
    void initData();

    /**
     * @brief 绘制精灵
     * @param positions 精灵位置列表
     * @param png 精灵图片名称
     * @param layerIndex 所在层
     */
    void drawSprite(std::vector<Vec2> positions, std::string png, int layerIndex);

    // 绘制墙壁
    void drawWall();
    // 绘制小球
    void drawBall();
    // 绘制箱子
    void drawBox();
    // 绘制角色
    void drawPlayer();

    // 初始化键盘事件
    void initKeyboardListener();

private:

    // 坐标是否在给定坐标列表中是
    bool inPosition(std::vector<Vec2> positions, Vec2 pos);

    // 角色能否移动
    bool canPlayerMove(Vec2 dirVector);

    /**
     * @brief 角色移动
     * 
     * @param dirVector 方向向量
     *  - Vec2(1,0):右
     *  - Vec2(-1,0):左
     *  - Vec2(0,1):上
     *  - Vec2(0,-1):下
     */
    void playerMove(Vec2 dirVector);
};

#endif // __HELLOWORLD_SCENE_H__
