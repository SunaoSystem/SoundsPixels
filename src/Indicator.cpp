//
//  Indicator.cpp
//  openNiSample007
//
//  Created by Tatsuhiko Suzuki on 14/02/04.
//
//

#include "Indicator.h"

void Indicator::setX(int _x){
    x = _x;
}

int Indicator::getX(){
    return x;
}

void Indicator::setSx(int _sx){
    sx = _sx;
}

void Indicator::setup(){
    setX(0);
    setSx(3);
}

void Indicator::update(){
    x = x+sx;
    if(x > ofGetWidth()) x = 0;
}

void Indicator::draw(){
    ofSetColor(255,200,0);
    ofSetLineWidth(3);
    ofLine(x,0,x,ofGetHeight());
}