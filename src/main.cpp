#include "ofMain.h"
#include "imageStackApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
    // taken from here
    // https://sites.google.com/site/ofauckland/examples/smoothing-edges-anti-aliasing
    // makes it smoother
    
    window.setGlutDisplayString("rgba double samples>=4"); // <--------- Smooth everything
	ofSetupOpenGL(&window, 1024,768, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new imageStackApp());

}
