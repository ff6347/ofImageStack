//
//  ofImageStack.cpp
//  imageStackApp
//
//  Created by Fabian Morón Zirfas on 13.05.13.
//
//

#include "ofImageStack.h"
#include <stdio.h>

ofImageStack::ofImageStack(string path_,int x_, int y_, int z_){
    
//    images = loadImages(path_);
    x = x_;
    y = y_;
    z = z_;
    ofDirectory dir;
    printf("Loading images from %s\n",path_.c_str());
    int nFiles = dir.listDir(path_);
    
    if(nFiles) {
        printf("found %d images\n",nFiles);
        
        for(int i=0; i<dir.numFiles(); i++) {
            
            // add the image to the vector
            string filePath = dir.getPath(i);
            images.push_back(ofImage());
            images.back().loadImage(filePath);
            images.back().mirror(true, false);
        }
    }else{
     printf("Could not find folder\n");   
    }
    

    
}

void ofImageStack::update(){
}

void ofImageStack::draw(){
    
    if((int)images.size() <= 0) {
        printf("No images in folder");
        return;
    }
    
    for (int i = 0; i< images.size(); i++) {
        images[i].draw(x, y, z + i);

    }
    
    
}


