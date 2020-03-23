#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundAuto(false);
  ofEnableAlphaBlending();
  ofBackground(255);
  clearAlpha = 100;
  timeScale = 0.5;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofColor darkColor(0, 0, 0, 255);  // opaque black
  ofColor lightColor(255, 255, 255, 255);  // opaque white

  float time = ofGetElapsedTimef();  // time in seconds
  float percent = ofMap(cos(time/2.0), -1, 1, 0, 1);  // create a value that oscillates between 0 and 1

  ofColor bgColor = darkColor;  // color for transparent rectangle used to clear the screen
  bgColor.lerp(lightColor, percent);  // modifies our color 'in place'
  bgColor.a = clearAlpha;  // initial color were opaque, but rectangles need to be transparent
  ofColor fgColor = lightColor;  // color for rectangles outline
  fgColor.lerp(darkColor, percent);  // modifies color in place

  ofSetColor(fgColor);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofFill();
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());  // ofBackground doesn't work with alpha, so draw transparent rectangle

  ofSetRectMode(OF_RECTMODE_CENTER);
  ofSetColor(bgColor);
  ofNoFill();

  ofPushMatrix();

  ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 5);  // translate to the center of the screen
  for (int i = 0; i < 100; i++) {
    ofScale(1.1, 1.1, 1.1);
    float time = ofGetElapsedTimef();
    float noise = ofSignedNoise(time * timeScale) * 2.0;
    ofRotate(noise);
    ofDrawRectangle(0, 0, 50, 50);
  }

  ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  clearAlpha = ofMap(x, 0, ofGetWidth(), 0, 255);  // clearalpha goes from 0 to 255 as mouse moves from left to right
  timeScale = ofMap(y, 0, ofGetHeight(), 0, 1);  // timeScale goes from 0 to 1 as mouse moves from top to bottom 
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
