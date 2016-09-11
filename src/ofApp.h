#pragma once

#define POINT_NUM 1000000

#include <random>
#include "ofMain.h"

#include "stars.h"

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
    
        void createVbo();
    
    
    private:
        ofVbo     _line;               // 線(VBO)
        ofVec3f   _points[POINT_NUM];  // 線に含まれる頂点
    
        ofEasyCam _cam;
        int       _prev_dir;
        float     _angle;
        ofVec3f   _max, _min, _center;
    
    
        // 背景に表示する球
        Stars* _stars;
};
