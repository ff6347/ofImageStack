#include "imageStackApp.h"

//--------------------------------------------------------------
void imageStackApp::setup(){
    firstStack = new ofImageStack("images/aemap_small",0,0,0);
    
}

//--------------------------------------------------------------
void imageStackApp::update(){

}

//--------------------------------------------------------------
void imageStackApp::draw(){

    
    firstStack->draw();
}

//--------------------------------------------------------------
void imageStackApp::keyPressed(int key){

}

//--------------------------------------------------------------
void imageStackApp::keyReleased(int key){

}

//--------------------------------------------------------------
void imageStackApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void imageStackApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void imageStackApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void imageStackApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void imageStackApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void imageStackApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void imageStackApp::dragEvent(ofDragInfo dragInfo){ 

}