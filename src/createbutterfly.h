#ifndef CREATEBUTTERFLY_H
#define CREATEBUTTERFLY_H
#include "ofMain.h"

class CreateButterfly
{
public:
    void draw();
    void update();
    void setup();
    vector<ofVec2f> circlePoints(int nDefinition, float rotation);
    int globDef;
    float rotation;
    ofVec2f sSpace;
    ofVec2f cRef;
    ofVec2f scale;
    vector<ofVec2f> c1;
    vector<ofVec2f> c2;
    vector<ofVec2f> finalPoints;


};

#endif // CREATEBUTTERFLY_H
