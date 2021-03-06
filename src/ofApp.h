#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

// #define _USE_LIVE_VIDEO
// uncomment this to use a live camera

// from example-contours-following
class Glow : public ofxCv::RectFollower {
    protected:
        ofColor color;
        ofVec2f cur, smooth;
        float startedDying;
        ofPolyline all;
    public:
        Glow()
        :startedDying(0) {
        }
        void setup(const cv::Rect& track);
        void update(const cv::Rect& track);
        void kill();
        void draw();
};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    ofPixels previous;
    ofImage diff;
    
    cv::Scalar diffMean;
    // a scalar is like an ofVec4f but normally used for storing color information
    
    #ifdef _USE_LIVE_VIDEO
          ofVideoGrabber cam;
    #else
          ofVideoPlayer cam;
    #endif
    
    ofxCv::ContourFinder contourFinder;
    ofxCv::ObjectFinder objectFinder;
    ofxCv::RectTrackerFollower<Glow> tracker;
    
    // GUI
    bool isGuiHidden;
    ofxIntSlider threshold;
    
//    ofxFloatSlider radius;
//    ofxColorSlider color;
//    ofxVec2Slider center;
//    ofxToggle filled;
//    ofxButton twoCircles;
//    ofxButton ringButton;
//    ofxLabel screenSize;
    
    ofxPanel gui;
    
    void thresholdChanged(int & threshold);
		
};
