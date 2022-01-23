#include "createbutterfly.h"
//-----------------------------------------------------------
void CreateButterfly::setup(){
    globDef = 100;
    sSpace = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);    //screen space
    cRef = sSpace/2.;
}
//-----------------------------------------------------------
void CreateButterfly::update(){
    c1 = circlePoints(globDef, 1);  //mainCircle
    finalPoints = c1;
    c2 = circlePoints(globDef, 0);  //mainCircle
    for(int i = 0; i < finalPoints.size(); i ++){
        float theta = (((TWO_PI / globDef) * i)); //rotation Offset
        float theta2 = ((((TWO_PI * 2) / globDef) * i)); //rotation Offset

        if(i < finalPoints.size() / 2){
            finalPoints[i].y -= c2[i].x * (cos(theta + (TWO_PI * (ofGetMouseX()) / ofGetWidth())));
            finalPoints[i].y -= c2[i].y * (cos(theta + (TWO_PI * (ofGetMouseY()) / ofGetHeight())));
        }
        else{
            finalPoints[i].y -= c2[i].x * (cos(theta + (TWO_PI * (ofGetMouseX()) / ofGetWidth())));
            finalPoints[i].y -= c2[i].y * (cos(theta + (TWO_PI * (ofGetMouseY()) / ofGetHeight())));
        }
    }
}

//-----------------------------------------------------------
void CreateButterfly::draw(){
    if(finalPoints.size() > 0){
        for(int i = 0; i < finalPoints.size(); i ++){
            finalPoints[i] *= sSpace / 2;
            finalPoints[i] += cRef * 2;
            cout << ", X= " << finalPoints[i].x;
            cout << " Y=" << finalPoints[i].y;
            if(i < finalPoints.size() / 2){
                ofSetColor(ofColor::green);
                ofDrawEllipse(finalPoints[i], 10, 10);
            }
            else{
                ofSetColor(ofColor::red);
                ofDrawEllipse(finalPoints[i], 10, 10);
            }
        }
    }
}
//-----------------------------------------------------------
vector<ofVec2f> CreateButterfly::circlePoints(int nDefinition, float rotation){
    vector<ofVec2f> _points;
    ofVec2f point;
    for(int i = 0; i < nDefinition; i ++){
        float theta = ((TWO_PI / nDefinition) * i) + (PI * rotation); //rotation Offset
        point.x = cos(theta);
        point.y = sin(theta);
        _points.push_back(point);
    }
    return _points;
}
