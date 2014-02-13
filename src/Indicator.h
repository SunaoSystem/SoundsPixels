//
//  Indicator.h
//  openNiSample007
//
//  Created by Tatsuhiko Suzuki on 14/02/04.
//
//

#pragma once
#include "ofMain.h"
#include "ofxOpenNI.h"

class Indicator : public ofBaseApp {
private:
    int x;
    int sx;
    
public:
    void setX(int _x);
    int getX();
    
    void setSx(int _sx);
    int getSx();
    
    void setup();
    void update();
    void draw();
    
    
};
