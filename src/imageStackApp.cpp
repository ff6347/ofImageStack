#include "imageStackApp.h"

//--------------------------------------------------------------
void imageStackApp::setup(){

//    vector<string>paths;
    paths.push_back("images/aemap_small");
    paths.push_back("images/loc_small");
    paths.push_back("images/mono_small");
    paths.push_back("images/swissd_small");
    
    // make an array of images
    //
    imageStacks = new ofImageStack*[paths.size()];
    int xpos = -512;
    int xstep = 256;
    // loop paths and make image stacks
    for (int i = 0; i < paths.size(); i++) {
        imageStacks[i] = new ofImageStack(paths[i],xpos,0,0);
        xpos+=xstep;
    }
    // this uses depth information for occlusion
	// rather than always drawing things on top of each other
	glEnable(GL_DEPTH_TEST);
    cam.setDistance(1000);

    // this is for snapshots
    snapCounter = 0;
	bSnapshot = false;
	memset(snapString, 0, 255);		// clear the string by setting all chars to 0
    
    string msg = string("Using mouse inputs to navigate (press 'c' to toggle): ") + (cam.getMouseInputEnabled() ? "YES" : "NO");
		msg += "\n\nLEFT MOUSE BUTTON DRAG:\nStart dragging INSIDE the yellow circle -> camera XY rotation .\nStart dragging OUTSIDE the yellow circle -> camera Z rotation (roll).\n\n";
		msg += "LEFT MOUSE BUTTON DRAG + TRANSLATION KEY (" + ofToString(cam.getTranslationKey()) + ") PRESSED\n";
		msg += "OR MIDDLE MOUSE BUTTON (if available):\n";
		msg += "move over XY axes (truck and boom).\n\n";
		msg += "RIGHT MOUSE BUTTON:\n";
		msg += "move over Z axis (dolly)";
        msg += "\n";
        msg += "PRESS h for interaction area overlay.";
    printf("%s\n",msg.c_str());
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
    
    // now for the screencrab aka snap
    
    if (bSnapshot == true){
		// grab a rectangle at 200,200, width and height of 300,180
		snap.grabScreen(0,0,ofGetWidth(),ofGetHeight());
        
		string fileName = "snapshot_"+ofToString(10000+snapCounter)+".png";
		snap.saveImage(fileName);
		printf( "saved %s\n", fileName.c_str());
		snapCounter++;
		bSnapshot = false;
	}
    
    if(help==true){
        drawInteractionArea();
    }
}

void imageStackApp::drawInteractionArea(){
	ofRectangle vp = ofGetCurrentViewport();
	float r = MIN(vp.width, vp.height) * 0.5f;
	float x = vp.width * 0.5f;
	float y = vp.height * 0.5f;
	
	ofPushStyle();
	ofSetLineWidth(3);
	ofSetColor(255, 255, 0);
	ofNoFill();
	glDepthMask(false);
	ofCircle(x, y, r);
	glDepthMask(true);
	ofPopStyle();
}

//--------------------------------------------------------------
void imageStackApp::keyPressed(int key){
	switch (key){
        case 'x':
		bSnapshot = true;
        break;
        case 'h':
            help = true;
	}
}

//--------------------------------------------------------------
void imageStackApp::keyReleased(int key){
    switch (key) {
        case 'h':
            help = false;
            break;
    }
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