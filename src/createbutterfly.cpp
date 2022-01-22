#include "createbutterfly.h"
//-----------------------------------------------------------
void CreateButterfly::setup(){
    globDef = 50;
    sSpace = ofVec2f(ofGetWidth(), ofGetHeight());    //screen space
    cRef = sSpace/2.;
}
//-----------------------------------------------------------
void CreateButterfly::update(){
    c1 = circlePoints(globDef, 0);  //mainCircle
    finalPoints = c1;
    for(int i = 0; i < finalPoints.size(); i ++){
        float theta = (((TWO_PI / globDef) * i)); //rotation Offset
        //float x = finalPoints[i].x;
        //float y = finalPoints[i].y;
        if(i < finalPoints.size() / 2){
            finalPoints[i].x -= finalPoints[i].x * (sin(theta) * 0.1);
            finalPoints[i].y -= finalPoints[i].y * (cos(theta) * (ofGetMouseX()) / ofGetWidth());
            //x *= cos(theta) + 0.1;
        }
        ///ofVec2f end = ofVec2f(x, y);
        //finalPoints[i] = end;
    }
}

//-----------------------------------------------------------
void CreateButterfly::draw(){
    if(finalPoints.size() > 0){
        for(int i = 0; i < finalPoints.size(); i ++){
            finalPoints[i] *= sSpace / 2;
            finalPoints[i] += cRef;
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
