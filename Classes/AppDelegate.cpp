#include "AppDelegate.h"
#include "HelloWorldScene.h"

// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

#include "CommonUtil.h"

USING_NS_CC;

static cocos2d::Size resolutionSize = cocos2d::Size(768, 768);

AppDelegate::AppDelegate() noexcept
{
}

AppDelegate::~AppDelegate()
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// 设置 OpenGL环境
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8, 0 };

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

// 逻辑初始化
bool AppDelegate::applicationDidFinishLaunching() {
    // 初始化 director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    // 初始化 opengl 试图
    if (!glview) {
        glview = GLViewImpl::createWithRect(CommonUtil::GBKToUTF8("推箱子"), cocos2d::Rect(0, 0, resolutionSize.width, resolutionSize.height));
        director->setOpenGLView(glview);
    }

    // 开启左下角 FPS 状态信息
    // director->setDisplayStats(true);
    // 设置 FPS 为 60, 默认为 60
    director->setAnimationInterval(1.0f / 60);

    // 设置屏幕分辨率
    glview->setDesignResolutionSize(resolutionSize.width, resolutionSize.height, ResolutionPolicy::NO_BORDER);

    register_all_packages();

    // 创建 Hello World 场景, 对象的释放交给 cocos2d-x 管理
    auto scene = HelloWorld::createScene();

    // 运行
    director->runWithScene(scene);

    return true;
}

// 切换到后台
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// 切换到前台
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
