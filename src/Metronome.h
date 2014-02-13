//
//  metronome.h
//  openNiSample007
//
//  Created by Tatsuhiko Suzuki on 14/02/08.
//
//

#pragma once
#include "ofMain.h"

class Metronome : public ofBaseApp{
    
public:
    void setup();
    void update();
    int getBeat();
    void updateJustBeat();
    int getJustBeat();
    
    unsigned long time;
    unsigned long ptime;
    int beat;
    int p_beat;
    int all_beats;
    
    int justBeat;
};
