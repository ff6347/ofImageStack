#include "imageStackApp.h"

//--------------------------------------------------------------
void imageStackApp::setup(){

//    vector<string>paths;
    paths.push_back("images/aemap_small");
    paths.push_back("images/loc_small");
    paths.push_back("images/mono_small");
    paths.push_back("images/swissd_small");
    
    imageStacks = new ofImageStack*[paths.size()];

    int xpos = -512;
    int xstep = 256;
    for (int i = 0; i < paths.size(); i++) {
        imageStacks[i] = new ofImageStack(paths[i],xpos,0,0);
        xpos+=xstep;
    }
//    firstStack = new ofImageStack("images/aemap_small",0,0,0);
    
    // this uses depth information for occlusion
	// rather than always drawing things on top of each other
	glEnable(GL_DEPTH_TEST);
    cam.setDistance(1000);

}

//--------------------------------------------------------------
void imageStackApp::update(){
   
}

//--------------------------------------------------------------
void imageStackApp::draw(){
	cam.begin();
	ofRotateX(ofRadToDeg(.5));
	ofRotateY(ofRadToDeg(-.5));
    for (int i = 0; i < paths.size(); i++) {
        imageStacks[i]->draw();
    }
//    firstStack->draw();
    
    cam.end();
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