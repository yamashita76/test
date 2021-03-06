#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;


USING_NS_CC;

CCScene* HelloWorld::scene()
{
	CCLog("aaaaaaaa");
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(-100,50);
    this->addChild(pMenu, 1);


    /////////////////////////////
    // 2. add a menu item with change scene
       CCMenuItemImage *pChangeSceneItem2 = CCMenuItemImage::create(
                                                                   "CloseNormal.png",
                                                                   "CloseSelected.png",
                                                                   this,
                                                                   menu_selector(HelloWorld::menuChangeScene) );
       pChangeSceneItem2->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width -20, 20) );

       // create menu, it's an autorelease object
       CCMenu* pMenu2 = CCMenu::create(pChangeSceneItem2, NULL);
       pMenu2->setPosition(-100,150);
       this->addChild(pMenu2, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 50);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
    CCSprite* image = CCSprite::create("image.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    image->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    image->setTag(100);
   // image->setScale(2.5);
    // add the sprite as a child to this layer
    setTouchEnabled(true);
    setKeypadEnabled(true);
    this->scheduleUpdate();
    CCMoveTo* move = CCMoveTo::create(2.0f,ccp(100,200));
    image->runAction(move);
    this->addChild(pSprite, 0);
    this->addChild(image,1);



    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("field.mp3");
    SoundPlayer();
     // create menu, it's an autorelease object


    return true;
}

void HelloWorld::SoundPlayer()
{
	  SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(2.0);
	  SimpleAudioEngine::sharedEngine()->playBackgroundMusic("c.mp3", true);
}
void HelloWorld::ccTouchEnded(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent )
{
	CCSetIterator it;
	CCTouch *touch;
	for(it=pTouch->begin();it!=pTouch->end();it++)
	{
		touch = (CCTouch*)(*it);
		if(!touch)
			break;

		CCPoint location = touch->getLocationInView();
		location = CCDirector::sharedDirector()->convertToGL(location);
		CCLog("touch ended=%f,y=%f",location.x,location.y);
	}




}

void HelloWorld::update(float delta)
{


}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
	//CCDirector::sharedDirector()->popScene();
}

void HelloWorld::menuChangeScene(CCObject* pSender)
{
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CCDirector::sharedDirector()->popScene();
}

