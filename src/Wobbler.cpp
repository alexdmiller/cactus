#include "Wobbler.hpp"
#include "ofApp.h"

void Wobbler::draw() {
  ofSetColor(255, 255, 255);
  t += 0.1;
//  float vertical = getApp()->getMouseVelocity().dot(ofPoint(0, 1)) / 5 + 2;
//  float horizontal = getApp()->getMouseVelocity().dot(ofPoint(1, 0)) / 5 + 2;
//  float mag = getApp()->getMouseVelocity().length();
//  t += mag / 100.0;
//
//  for (int j = 0; j < groups->size(); j++) {
//    for (int i = 0; i < groups->at(j).size(); i++) {
//      ofMesh* mesh = groups->at(j)[i];
//      if (mesh->getNumVertices() > 0) {
//        ofSetLineWidth(2);
//        float lastX = mesh->getVertex(0).x + cos(t) * 10;
//        float lastY = mesh->getVertex(0).y + sin(t) * 10;
//        for (int k = 0; k < (int) mesh->getNumVertices() - 1; k++) {
//          float x = mesh->getVertex(k).x + cos(t + k / 3.0) * 10;
//          float y = mesh->getVertex(k).y + sin(t + k / 3.0) * 10;
//          ofDrawLine(lastX, lastY, x, y);
//          lastX = x;
//          lastY = y;
//        }
//      }
//    }
//  }
  
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
  return ofPoint(
                 p.x + cos(p.y / 10.0 + t) * 10,
                 p.y + sin(p.x / 10.0 + t) * 10);
//  return ofPoint(
//                 p.x + cos(t + k / 3.0) * 10,
//                 p.y + sin(t + k / 3.0) * 10);
}

