//
//  metronome.m
//  openNiSample007
//
//  Created by Tatsuhiko Suzuki on 14/02/08.
//
//

#include "ofMain.h"
#include "metronome.h"

void Metronome::setup(){
    
    time = 0;
    ptime = 0;
    beat = 0;
    p_beat = 0;
    all_beats = 0;
    
    justBeat = 0;

}

void Metronome::update(){
    
    //ofGetElapsedTimeMillis() プログラムが始まってからの時間
    if(ofGetElapsedTimeMillis() > 1000)
        time = ofGetElapsedTimeMillis()-1000;
    
    beat = (time-ptime)/(60000/128/4)+1;//+1は0をなくすため
    if(beat>32){
        beat = 1;
        ptime = time;
    }
    
    //博が変わったら、beatsが増えてゆく
    if(beat != p_beat) all_beats++;
    
    p_beat = beat;
    
    updateJustBeat();
    
}

void Metronome::updateJustBeat(){
    
    static int pbeat;
    
    if(beat != pbeat)      justBeat = beat;
    else if(beat == pbeat) justBeat = 0;
    
    pbeat = beat;
    
}


int Metronome::getBeat(){
    return beat;
}


int Metronome::getJustBeat(){
    return justBeat;
}

