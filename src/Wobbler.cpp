#include "Wobbler.hpp"
#include "ofApp.h"

void Wobbler::draw() {
  ofSetColor(255, 255, 255);
  
  float mag = getApp()->getMouseVelocity().length();
  t += mag / 50.0f + 0.01f;
    
  for (int j = 0; j < groups->size(); j++) {
    for (int i = 0; i < groups->at(j).size(); i++) {
      ofMesh* mesh = groups->at(j)[i];
      if (mesh->getNumVertices() > 0) {
        ofSetLineWidth(2);
        ofPoint last = f(mesh->getVertex(0), 0);
        for (int k = 0; k < (int) mesh->getNumVertices() - 1; k++) {
          ofPoint current = f(mesh->getVertex(k), k);
          ofDrawLine(last, current);
          last = current;
        }
      }
    }
  }
}

ofPoint Wobbler::f(ofPoint p, int k) {
  float vertical = getApp()->getMouseVelocity().dot(ofPoint(0, 1)) / 2 + 2;
  float horizontal = getApp()->getMouseVelocity().dot(ofPoint(1, 0)) / 2 + 2;

  return ofPoint(
                 p.x + cos(p.y / 10.0 + t) * horizontal,
                 p.y + sin(p.x / 10.0 + t) * vertical);
//  return ofPoint(
//                 p.x + cos(t + k / 3.0) * 10,
//                 p.y + sin(t + k / 3.0) * 10);
}

