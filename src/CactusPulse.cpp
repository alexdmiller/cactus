#include "CactusPulse.hpp"
#include "ofApp.h"

void CactusPulse::draw() {
  float horizontal = getApp()->getMouseVelocity().dot(ofPoint(1, 0));
  t += horizontal / 50;
  
  for (int j = 0; j < groups->size(); j++) {
    ofNoFill();
    for (int i = 0; i < groups->at(j).size(); i++) {
      ofMesh* mesh = groups->at(j)[i];

      float w = (sin((float) j * 10 + (float) i / 5 + t) + 1) / 2;
      if (w > 0.5) {
        ofSetLineWidth(w * w * w * 10);
        for (int j = 0; j < (int) mesh->getNumVertices() - 1; j++) {
          ofDrawLine(mesh->getVertex(j), mesh->getVertex(j + 1));
        }
      }
    }
  }
}