//
//  DancePixel.m
//  openNiSample007
//
//  Created by Tatsuhiko Suzuki on 14/01/31.
//
//

#include "testApp.h"
#include "DancePixel.h"
#include "Indicator.h"
#include "Metronome.h"

void DancePixel::init(int _setup_x, int _setup_y, int _setup_width){
    
    setup_x = _setup_x;
    setup_y = _setup_y;
    setup_width =  _setup_width;
    setup_height = _setup_width;
    
    x = setup_x;
    y = setup_y;
    target_x = setup_x;
    target_y = setup_y;
    random_x = setup_x+ofRandom(0,-200);
    random_y = setup_y+ofRandom(200,-200);
    flow_x = 0;
    flow_y = 0;
    
    
    width = setup_width;
    height = setup_height;
    
    indicator_flg = FALSE;
    
    
    dot_white.loadImage("img_dot/dot_white.png");
    dot_blue.loadImage("img_dot/dot_blue.png");
    dot_pink.loadImage("img_dot/dot_pink.png");
    dot_green.loadImage("img_dot/dot_green.png");
    dot_orange.loadImage("img_dot/dot_orange.png");
    dot = dot_blue;
    dot = dot_pink;
    dot = dot_green;
    dot = dot_orange;
    dot = dot_white;
    
    /*
    dot_white.allocate(30,30,OF_IMAGE_COLOR);
    dot_blue.allocate(30,30,OF_IMAGE_COLOR);
    dot_pink.allocate(30,30,OF_IMAGE_COLOR);
    dot_green.allocate(30,30,OF_IMAGE_COLOR);
    dot_orange.allocate(30,30,OF_IMAGE_COLOR);
    */
    
    /*
    honey_white.loadImage("img_honey/honey_white.png");
    honey_blue.loadImage("img_honey/honey_blue.png");
    honey_pink.loadImage("img_honey/honey_pink.png");
    honey_green.loadImage("img_honey/honey_green.png");
    honey_orange.loadImage("img_honey/honey_orange.png");
    honey = honey_white;
    */
    /*
    tri_white.loadImage("img_tri/tri_white.png");
    tri_blue.loadImage("img_tri/tri_blue.png");
    tri_pink.loadImage("img_tri/tri_pink.png");
    tri_green.loadImage("img_tri/tri_green.png");
    tri_orange.loadImage("img_tri/tri_orange.png");
    tri = tri_white;
    */
    /*
    dai_white.loadImage("img_dai/dai_white.png");
    dai_blue.loadImage("img_dai/dai_blue.png");
    dai_pink.loadImage("img_dai/dai_pink.png");
    dai_green.loadImage("img_dai/dai_green.png");
    dai_orange.loadImage("img_dai/dai_orange.png");
    dai = dai_white;
    */
    
    img = dot_white;
     
}

void DancePixel::reset(){
    
    //any_userを初期化
    any_user = FALSE;
    //user[0~9]を初期化
    for(char i=0; i<10; i++){
        user[i] = FALSE;
    }
}

void DancePixel::update(){
    
    x = x-(x-target_x)/5;
    y = y-(y-target_y)/5;
    width = width-(width-target_width)/5;
    height = height-(height-target_height)/5;
    
    updateUserStatus();
    updateIndicatorStatus();
    updateColorStatus();
    updateSizeStatus();
    updateMotionStatus();
    updateSoundStatus();
}

void DancePixel::updateUserStatus(){
    
    
    for(char i=0; i<10; i++){//USERのだれかがTRUEであれば any_userもtrue
        if(user[i] == TRUE){
            any_user = TRUE;
        }
    }
    
}

void DancePixel::updateColorStatus(){
    if(n_indicator_flg == FALSE || indicator_flg == TRUE){
        if(any_user == FALSE){
            color_flg = WHITE;
        }
        else if(user[1] == TRUE){
            color_flg = BLUE;
        }
        else if(user[2] == TRUE){
            color_flg = PINK;
        }
        else if(user[3] == TRUE){
            color_flg = GREEN;
        }
        else if(user[4] == TRUE){
            color_flg = ORANGE;
        }
    }
    if(color_flg != past_color_flg){
        if(color_flg == WHITE ) img = dot_white ;
        else if(color_flg == BLUE  ) img = dot_blue;
        else if(color_flg == PINK  ) img = dot_pink;
        else if(color_flg == GREEN ) img = dot_green;
        else if(color_flg == ORANGE) img = dot_orange;
    }
    
    past_color_flg = color_flg;
}

void DancePixel::updateSoundStatus(){
    if(any_user == FALSE){
        sound_user_flg = 0;
    }
    else if(user[1] == TRUE){
        sound_user_flg = 1;
    }
    else if(user[2] == TRUE){
        sound_user_flg = 2;
    }
    else if(user[3] == TRUE){
        sound_user_flg = 3;
    }
    else if(user[4] == TRUE){
        sound_user_flg = 4;
    }
    else if(user[5] == TRUE){
        sound_user_flg = 5;
    }
    else if(user[6] == TRUE){
        sound_user_flg = 6;
    }
    
}

void DancePixel::updateIndicatorStatus(){
    if(n_indicator_flg != p_indicator_flg){
        indicator_flg = TRUE;
    }
    else{
        indicator_flg = FALSE;
    }
    p_indicator_flg = n_indicator_flg;
}


void DancePixel::updateSizeStatus(){
    if(n_indicator_flg == FALSE || indicator_flg == TRUE){
        if(any_user == TRUE){
            setTargetWidth(30);
            setTargetHeight(30);
        }
        else{
            setTargetWidth(10);
            setTargetHeight(10);
        }
    }
}

void DancePixel::updateMotionStatus(){
    
    if(indicator_flg == TRUE){
        if(any_user == TRUE){
            pop_flg = TRUE;
        }
    }
    else if (n_indicator_flg == FALSE){
        pop_flg = FALSE;
        setTargetX(setup_x);
        setTargetY(setup_y);
        flow_x = 0;
        flow_y = 0;
        rotation = 0;
        
    }
    if(pop_flg == TRUE){
        flow_x = flow_x + ((setup_x -random_x)/80);
        flow_y = flow_y + ((setup_y -random_y)/80);
        setTargetX(random_x - flow_x);
        setTargetY(random_y - flow_y);
        rotation = rotation + ((setup_x-random_x)+(setup_y-random_y))/40;
    }
}

void DancePixel::draw(){
    ofPushMatrix();
    ofTranslate(x,y);
    ofRotate(rotation);
    img.draw(-width/2,-height/2,width,height);
    ofPopMatrix();
}

char DancePixel::getUser(){
    return any_user;
}

char DancePixel::getUser(char _user_num){
    return user[_user_num];
};
void DancePixel::setUser(bool _user, char _user_num){
    user[_user_num] = _user;
};

double DancePixel::getWidth(){};
double DancePixel::getHeight(){};
double DancePixel::getTargetWidth(){};
double DancePixel::getTargetHeight(){};

double DancePixel::getX(){};
double DancePixel::getY(){};
double DancePixel::getTargetX(){};
double DancePixel::getTargetY(){};
double DancePixel::getSetupX(){
    return setup_x;
};
double DancePixel::getSetupY(){};

bool DancePixel::getIndicaterFlg(){
    return indicator_flg;
};

char DancePixel::getSoundUserFlg(){
    return sound_user_flg;
};

void DancePixel::setWidth(double _width){
    width = _width;
};
void DancePixel::setHeight(double _height){
    height = _height;
};
void DancePixel::setTargetWidth(double _target_width){
    target_width = _target_width;
};

void DancePixel::setTargetHeight(double _target_height){
    target_height = _target_height;
};

void DancePixel::setX(double x){};
void DancePixel::setY(double y){};
void DancePixel::setTargetX(double _target_x){
    target_x = _target_x;
};
void DancePixel::setTargetY(double _target_y){
    target_y = _target_y;
};
void DancePixel::setSetupX(double setup_x){};
void DancePixel::setSetupY(double setup_y){};

void DancePixel::setNowIndicatorFlg(bool _n_indicator_flg){
    n_indicator_flg = _n_indicator_flg;
};

void DancePixel::setup(){};
