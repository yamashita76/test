#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "TitleScene.h"
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);


    ChangeResolution();



    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = Title::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

void AppDelegate::ChangeResolution()
{
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CCEGLView* view = CCDirector::sharedDirector()->getOpenGLView();
	CCSize frame = view->getFrameSize();
	if (frame.height==1136.0)
	{
		// iPhone5�Ȃǂ̉𑜓x
		CCEGLView::sharedOpenGLView()->setDesignResolutionSize(320, 568, kResolutionExactFit);
	}
	else
	{
		CCEGLView::sharedOpenGLView()->setDesignResolutionSize(480, 320, kResolutionExactFit);
	}
	#else
		// Android�p
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(480, 320, kResolutionExactFit);

	#endif
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
