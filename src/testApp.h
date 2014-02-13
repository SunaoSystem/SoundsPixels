#pragma once
#include "ofMain.h"
#include "ofxOpenNI.h"
#include "DancePixel.h"
#include "Indicator.h"
#include "Metronome.h"

class testApp : public ofBaseApp {
private:
    ofxOpenNI kinect;
public:
    void setup();
    void update();
    void updateIndicatorFlgStatus(int i,int j);
    void updateMetronomeStatus(int i,int j);
    void draw();
    void playSound();
    void keyPressed (int key);
    void keyReleased (int key);
    void mouseMoved (int x, int y);
    void mouseDragged (int x, int y, int button);
    void mousePressed (int x, int y, int button);
    void mouseReleased (int x, int y, int button);
    void windowResized (int w, int h);
    void dragEvent (ofDragInfo dragInfo);
    void gotMessage (ofMessage msg);
    void exit();
    
    void userEvent(ofxOpenNIUserEvent & event);
    
    ofTexture maskTexture;
    ofImage dot_st;
    
    bool trg;
    
    int user_FALSE_flg;
    
    int dots_width = 1280;
    int dots_height =1024;
    
    //
    int num_dp_x = 32;
    int num_dp_y =24;
    DancePixel dancePixel[32+1][24+1];
    bool isTrackingUser[10+1];
    bool stop_skeleton_flg[10+1];
    bool skeleton_flg[10+1];
    
    bool stop_tracking_flg;
    
    Indicator indicator;
    Metronome metronome;
    
    ofSoundPlayer sound[6][24];
    int a;
    
};
