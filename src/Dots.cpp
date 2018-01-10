#include "Dots.hpp"

void Dots::draw() {
  for (int j = 0; j < groups->size(); j++) {
    for (int i = 0; i < groups->at(j).size(); i++) {
      ofMesh* mesh = groups->at(j)[i];
      ofSetLineWidth(2);
      float lastX = mesh->getVertex(0).x + cos(ofGetElapsedTimef() * 10) * 5;
      float lastY = mesh->getVertex(0).y + sin(ofGetElapsedTimef() * 10) * 5;
      for (int k = 0; k < (int) mesh->getNumVertices() - 1; k++) {
        float x = mesh->getVertex(k).x + cos(ofGetElapsedTimef() * 10 + k / 5.0) * 5;
        float y = mesh->getVertex(k).y + sin(ofGetElapsedTimef() * 10 + k / 5.0) * 5;
        ofDrawLine(lastX, lastY, x, y);
        lastX = x;
        lastY = y;
      }
    }
  }
}