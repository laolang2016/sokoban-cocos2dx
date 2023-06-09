/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

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
    // 详细图片
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
};

#endif // __HELLOWORLD_SCENE_H__
