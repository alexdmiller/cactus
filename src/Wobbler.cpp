#include "Wobbler.hpp"
#include "ofApp.h"

void Wobbler::draw() {
  ofSetColor(255, 255, 255);
  float vertical = getApp()->getMouseVelocity().dot(ofPoint(0, 1)) / 5 + 2;
  float horizontal = getApp()->getMouseVelocity().dot(ofPoint(1, 0)) / 5 + 2;
  float mag = getApp()->getMouseVelocity().length() / 100 + 1;

  for (int j = 0; j < groups->size(); j++) {
    for (int i = 0; i < groups->at(j).size(); i++) {
      ofMesh* mesh = groups->at(j)[i];
      if (mesh->getNumVertices() > 0) {
        ofSetLineWidth(2);
        float lastX = mesh->getVertex(0).x + cos(ofGetElapsedTimef() * mag) * 5 * horizontal;
        float lastY = mesh->getVertex(0).y + sin(ofGetElapsedTimef() * mag) * 5 * vertical;
        for (int k = 0; k < (int) mesh->getNumVertices() - 1; k++) {
          float x = mesh->getVertex(k).x + cos(ofGetElapsedTimef() * mag + k / 5.0) * 5 * horizontal;
          float y = mesh->getVertex(k).y + sin(ofGetElapsedTimef() * mag + k / 5.0) * 5 * vertical;
          ofDrawLine(lastX, lastY, x, y);
          lastX = x;
          lastY = y;
        }
      }
    }
  }
}