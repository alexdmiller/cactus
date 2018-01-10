#include "Crawler.hpp"
#include "ofApp.h"

void Crawler::draw() {
  t -= getApp()->getMouseVelocity().dot(ofPoint(0, 1)) / 30.0;
  float horizontal = getApp()->getMouseVelocity().dot(ofPoint(1, 0)) * 3;
  
  for (int j = 0; j < groups->size(); j++) {
    for (int i = 0; i < groups->at(j).size(); i++) {
      ofMesh* mesh = groups->at(j)[i];
      
      ofFill();

      float w = (sin((float) (i * 5) + (float) 0 / 5 + t + ofGetElapsedTimef() * 5) + 1) / 2;
      w = w * w * w * w;
      ofPoint last(mesh->getVertex(0));
      last.x += horizontal * w;
      for (int k = 1; k < (int) mesh->getNumVertices(); k++) {
        ofPoint current = mesh->getVertex(k);
        w = (sin((float) (i * 5) + (float) k / 5 + t + ofGetElapsedTimef() * 5) + 1) / 2;
        w = w * w * w * w;
        current.x += horizontal * w;

        ofDrawCircle(current, w * 10);
        last = current;
      }
    }
  }
}