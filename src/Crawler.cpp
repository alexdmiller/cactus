#include "Crawler.hpp"
#include "ofApp.h"

void Crawler::draw() {
  t -= getApp()->getMouseVelocity().dot(ofPoint(0, 1)) / 30.0;
  float horizontal = getApp()->getMouseVelocity().dot(ofPoint(1, 0)) * wobbleAmount;
  
  ofFill();
  ofSetColor(255, 255, 255);

  for (int j = 0; j < groups->size(); j++) {
    for (int i = 0; i < groups->at(j).size(); i++) {
      ofMesh* mesh = groups->at(j)[i];
      
      float w = (sin((float) (i * 5) + (float) 0 / 5 + t + ofGetElapsedTimef() * 5) + 1) / 2;
      w = w * w * w * w;
      ofPoint last(mesh->getVertex(0));
      last.x += horizontal * w;
      for (int k = 1; k < (int) mesh->getNumVertices(); k++) {
        ofPoint current = mesh->getVertex(k);
        w = (sin((float) (i * 5) + (float) k / pulseSparsity + t + ofGetElapsedTimef() * 2) + 1) / 2;
        w = w * w * w * w;
        current.x += horizontal * w;

        ofDrawCircle(current, w * lineWeight);
        last = current;
      }
    }
  }
}