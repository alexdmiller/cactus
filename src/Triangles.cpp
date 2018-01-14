//
//  Triangles.cpp
//  Mask Test
//
//  Created by Alex on 1/9/18.
//
//

#include "Triangles.hpp"
#include "ofApp.h"

void Triangles::draw() {
  float horizontal = getApp()->getMouseVelocity().dot(ofPoint(1, 0));
  float vertical = getApp()->getMouseVelocity().dot(ofPoint(0, 1));
  horizontalT += horizontal;
  verticalT += vertical;
  
  auto triangles = mesh->getUniqueFaces();
  
  ofFill();
  for (int i = 0; i < triangles.size(); i++) {
    ofMeshFace tri = triangles.at(i);
    ofPoint points[] = { tri.getVertex(0), tri.getVertex(1), tri.getVertex(2) };
    
    ofPoint average;
    average.average(points, 3);
    
    ofSetColor(ofFloatColor(ofMap(
                                  sin((average.x - horizontalT) / 100 + (average.y + verticalT) / 100 + ofGetElapsedTimef() / 3),
                                  -1, 1, 0, 1)));
    
    ofDrawTriangle(tri.getVertex(0), tri.getVertex(1), tri.getVertex(2));
  }
}
