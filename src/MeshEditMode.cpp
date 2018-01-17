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
  for (int j = 0; j < meshes->size(); j++) {
    ofMesh* mesh = meshes->at(j);
    
    if (selectedMesh == j) {
      ofSetColor(0, 255, 255);
    } else {
      ofSetColor(255, 255, 255);
    }
    mesh->draw(OF_MESH_WIREFRAME);
  
    ofNoFill();
    for (int i = 0; i < mesh->getNumVertices(); i++) {
      ofDrawCircle(mesh->getVertex(i), 10);
    }
  }
}

void MeshEditMode::drawUI() {
  ofDrawBitmapString("mesh = " + ofToString(selectedMesh), 0, 0);
  
  ofDrawBitmapString("C   new group\n"
                     "N   next mesh\n"
                     "click to add vertex\n"
                     "shift + click to add index",
                     0, 40);
}

void MeshEditMode::mouseMoved(float x, float y) {
  
}

void MeshEditMode::mouseDragged(float x, float y) {
  if (selectedMesh >= 0 && selectedIndex >= 0) {
    meshes->at(selectedMesh)->setVertex(selectedIndex, ofPoint(x, y));
  }
}

void MeshEditMode::mousePressed(float x, float y) {
  ofPoint m(x, y);
  if (selectedMesh >= 0) {
    for (int i = 0; i < meshes->at(selectedMesh)->getNumVertices(); i++) {
      ofPoint p = meshes->at(selectedMesh)->getVertex(i);
      if (p.distance(m) < 10) {
        if (shiftDown) {
          meshes->at(selectedMesh)->addIndex(i);
        } else {
          selectedIndex = i;
        }
        return;
      }
    }
    
    meshes->at(selectedMesh)->addVertex(m);
  }
}

void MeshEditMode::mouseReleased(float x, float y) {
  selectedIndex = -1;
}

void MeshEditMode::keyPressed(int key) {
  cout << key << "\n";
  if (key == 2304) {
    shiftDown = true;
  } else if (key == 116) {
    getApp()->transformMeshToGroups();
  } else if (key == 99) {
    ofMesh* mesh = new ofMesh();
    meshes->push_back(mesh);
    selectedMesh = meshes->size() - 1;
  } else if (key == 110) {
    selectedMesh = (selectedMesh + 1) % meshes->size();
  }
}

void MeshEditMode::keyReleased(int key) {
  if (key == 2304) {
    shiftDown = false;
  }
}