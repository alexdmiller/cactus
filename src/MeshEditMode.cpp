//
//  CactusMode.cpp
//  Mask Test
//
//  Created by Alex on 1/4/18.
//
//

#include "MeshEditMode.hpp"
#include "ofApp.h"


void MeshEditMode::draw() {
  ofSetColor(255);
  mesh->draw(OF_MESH_WIREFRAME);
  
  ofNoFill();
  for (int i = 0; i < mesh->getNumVertices(); i++) {
    ofDrawCircle(mesh->getVertex(i), 10);
  }
  
  if (selectedIndex >= 0 && shiftDown) {
    ofSetLineWidth(1);
    ofDrawLine(mesh->getVertex(selectedIndex), ofPoint(ofGetMouseX(), ofGetMouseY()));
  }
}

void MeshEditMode::drawUI() {
//  ofDrawBitmapString("group = " + ofToString(selectedGroup), 0, 0);
//  ofDrawBitmapString("line = " + ofToString(selectedLine), 0, 20);
//  
//  ofDrawBitmapString("C   new group\n"
//                     "L   new line\n"
//                     "N   next group\n"
//                     ">   next line",
//                     0, 40);
}

void MeshEditMode::mouseMoved(float x, float y) {
  
}

void MeshEditMode::mouseDragged(float x, float y) {
  if (selectedIndex >= 0) {
    if (shiftDown) {
      
    } else {
      mesh->setVertex(selectedIndex, ofPoint(x, y));
    }
  }
}

void MeshEditMode::mousePressed(float x, float y) {
  ofPoint m(x, y);
  for (int i = 0; i < mesh->getNumVertices(); i++) {
    ofPoint p = mesh->getVertex(i);
    if (p.distance(m) < 10) {
      if (shiftDown) {
        mesh->addIndex(i);
      } else {
        selectedIndex = i;
      }
      return;
    }
  }
  
  mesh->addVertex(m);
}

void MeshEditMode::mouseReleased(float x, float y) {
  selectedIndex = -1;
}

void MeshEditMode::keyPressed(int key) {
  if (key == 2304) {
    shiftDown = true;
  } else if (key == 116) {
    getApp()->transformMeshToGroups();
  }
}

void MeshEditMode::keyReleased(int key) {
  if (key == 2304) {
    shiftDown = false;
  }
}