//
//  ofImageStack.h
//  imageStackApp
//
//  Created by Fabian Morón Zirfas on 13.05.13.
//
//
#include "ofMain.h"
#ifndef __imageStackApp__ofImageStack__
#define __imageStackApp__ofImageStack__
class ofImageStack {
    public:
    
    void update();
    void draw();
//    vector <ofImage> images;
    ofImageStack(string path_, int x_, int y_, int z_);// constructor
    int x;
    int y;
    int z;
private:
    vector <ofImage> images;
};

#endif /* defined(__imageStackApp__ofImageStack__) */
