//
//  DancePixel.h
//  openNiSample007
//
//  Created by Tatsuhiko Suzuki on 14/01/31.
//
//
#pragma once
#include "ofMain.h"
#include "ofxOpenNI.h"
class DancePixel : public ofBaseApp {
private:
    //userがいるかどうか/user番号
    bool user[10];
    bool any_user;
    
    //大きさ関連
    double width;
    double height;
    double target_width;
    double target_height;
    double setup_width;
    double setup_height;
    
    //座標関連
    double x;
    double y;
    double target_x;
    double target_y;
    double setup_x;
    double setup_y;
    double random_x;
    double random_y;
    double flow_x;
    double flow_y;
    
    //インジケーターが通ったか
    bool n_indicator_flg;
    bool p_indicator_flg;
    bool indicator_flg;
    bool pop_flg;
    char sound_user_flg;
    
    ofColor pixel_color;
    
    ofImage dot_standard;
    
public:
    
    void init(int _setup_x, int _setup_y, int _setupWidth);
    
    char getUser();
    char getUser(char user_number);
    void setUser(bool _user, char _user_number);
    
    double getWidth();
    double getHeight();
    double getTargetWidth();
    double getTargetHeight();
    
    double getX();
    double getY();
    double getTargetX();
    double getTargetY();
    double getSetupX();
    double getSetupY();
    
    bool getIndicaterFlg();
    char getSoundUserFlg();
    
    void setWidth(double width);
    void setHeight(double height);
    void setTargetWidth(double target_width);
    void setTargetHeight(double target_height);
    
    void setX(double x);
    void setY(double y);
    void setTargetX(double target_x);
    void setTargetY(double target_y);
    void setSetupX(double setup_x);
    void setSetupY(double setup_y);
    
    void setNowIndicatorFlg(bool _n_indicator_flg);
    
    void setup();
    void reset();
    void update();
    void updateUserStatus();
    void updateSizeStatus();
    void updateColorStatus();
    void updateSoundStatus();
    void updateIndicatorStatus();
    void updateMotionStatus();
    void draw();
    
    ofImage dot_white;
    ofImage dot_blue;
    ofImage dot_pink;
    ofImage dot_green;
    ofImage dot_orange;
    ofImage dot;
    
    ofImage honey_white;
    ofImage honey_blue;
    ofImage honey_pink;
    ofImage honey_green;
    ofImage honey_orange;
    ofImage honey;
    
    ofImage tri_white;
    ofImage tri_blue;
    ofImage tri_pink;
    ofImage tri_green;
    ofImage tri_orange;
    ofImage tri;
    
    ofImage dai_white;
    ofImage dai_blue;
    ofImage dai_pink;
    ofImage dai_green;
    ofImage dai_orange;
    ofImage dai;
    
    ofImage img;

    
    char color_flg;
    char past_color_flg;
    const char WHITE  = 0;
    const char BLUE   = 1;
    const char PINK   = 2;
    const char GREEN  = 3;
    const char ORANGE = 4;
    
    int rotation;
};
