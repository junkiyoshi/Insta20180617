#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	float random_value_x = ofRandom(100);
	float random_value_y = ofRandom(100);
	vector<ofPoint> targets;
	for (int i = 0; i < 50; i++) {

		ofPoint target(ofMap(ofNoise(random_value_x, (ofGetFrameNum() - i) * 0.008), 0, 1, 0, ofGetWidth()), ofMap(ofNoise(random_value_y, (ofGetFrameNum() - i) * 0.008), 0, 1, 0, ofGetHeight()));
		targets.push_back(target);
	}

	ofColor color;
	for(int i = 0; i < 1280; i++){
	
		ofPoint point(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
		color.setHsb(ofRandom(255), 200, 255);
		float radius = ofRandom(3, 30);

		for (int targets_index = 0; targets_index < targets.size(); targets_index++) {
		
			float distance = point.distance(targets[targets_index]);
			if (distance < 120) {

				ofSetColor(color, ofMap(distance, 0, 120, 50 - targets_index, 0));
				ofDrawCircle(point, radius);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(1280, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}