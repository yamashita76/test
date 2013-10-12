#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    virtual void ccTouchEnded(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent );
    virtual void update(float delta);
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    void menuChangeScene(CCObject* pSender);
    void SoundPlayer();
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
