#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofHideCursor();
    
    _prev_dir = 0;
    _angle    = 0.0;
    
    this->createVbo();

    //_center = _max + _min / 2.0;
    _center = _max + _min;
    
    // 背景オブジェクトの設定
    _stars = new Stars(2000);
    _stars->setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    
    _cam.begin();
    _cam.setNearClip(0.000001);
    _cam.setFarClip(2000);
    _cam.setPosition(_center);
    _cam.setTarget(_center);
 
    ofRotateY(_angle);
    
    ofPushMatrix();
    
    _stars->draw();
    //ofRotateY(_angle);
    _line.draw(GL_LINE_STRIP, 0, POINT_NUM);
    _angle += 0.01;
    
    ofPopMatrix();
    _cam.end();
    
}

void ofApp::createVbo(){
    _points[0] = ofVec3f(0, 0, 0);
    
    
    // 被決定的な乱数生成器でシード生成器を生成
    std::random_device rnd;
    // メルセンヌ・ツイスタ 引数は初期シード値 ファンクタを渡す
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<int> rand5(0,5); // [0, 5]の一様乱数
    
    float max = 0.0001;
    float min = 0.0;
    
    float xmin = 0.0, ymin = 0.0, zmin = 0.0;
    float xmax = 0.0, ymax = 0.0, zmax = 0.0;
    
    for(int i = 1; i < POINT_NUM; i++){
        
        // どの軸の方向に頂点を追加するかを決定
        // 0 : X軸方向(+)
        // 1 : X軸方向(-)
        // 2 : Y軸方向(+)
        // 3 : Y軸方向(-)
        // 4 : Z軸方向(+)
        // 5 : Z軸方向(-)
        // ofRandomはfloat方の値が帰ってくるため、rand関数を使用する
        ofVec3f base = _points[i - 1];
        //int dir      = rand() % 6;
        int dir        = rand5(mt);
        // 前回と同じ方向ならやり直し
        while(_prev_dir == dir || _prev_dir == -dir){
            dir = rand5(mt);
        }

        float length = 1.0;

        
        switch(dir){
            case 0:
                _points[i] = ofVec3f(ofRandom(min, max), 0, 0) * length + base;
                break;
            case 1:
                _points[i] = ofVec3f(-ofRandom(min, max), 0, 0) * length + base;
                break;
            case 2:
                _points[i] = ofVec3f(0, ofRandom(min, max), 0) * length + base;
                break;
            case 3:
                _points[i] = ofVec3f(0, -ofRandom(min, max), 0) * length + base;
                break;
            case 4:
                _points[i] = ofVec3f(0, 0, ofRandom(min, max)) * length + base;
                break;
            case 5:
                _points[i] = ofVec3f(0, 0, -ofRandom(min, max)) * length + base;
                break;
        }
        
        _prev_dir = dir;
        if(_points[i].x < xmin) xmin = _points[i].x;
        if(_points[i].y < ymin) ymin = _points[i].y;
        if(_points[i].z < zmin) zmin = _points[i].z;
        if(_points[i].x > xmax) xmax = _points[i].x;
        if(_points[i].y > ymax) ymax = _points[i].y;
        if(_points[i].z > zmax) zmax = _points[i].z;
        
    }

    _max = ofVec3f(xmax, ymax, zmax);
    _min = ofVec3f(xmin, ymin, zmin);
    
    _line.setVertexData(_points, POINT_NUM, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        _angle += 10.0;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
