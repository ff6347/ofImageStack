#pragma once

#include "ofMain.h"
#include "ofImageStack.h"

//#define NSTACKS 4

class imageStackApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofImageStack** imageStacks;
    ofEasyCam cam; // add mouse controls for camera movement
    vector<string>paths;

};
