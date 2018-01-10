#include "Mesh.hpp"

void Mesh::draw() {
  for (int j = 0; j < groups->size(); j++) {
    int maxLength = 0;
    for (int i = 0; i < groups->at(j).size() - 1; i++) {
      if (groups->at(j)[i]->getNumVertices() > maxLength) {
        maxLength = groups->at(j)[i]->getNumVertices();
      }
    }

    ofSetLineWidth(2);
    ofSetColor(255, 255, 255);
    for (int k = 0; k < 5; k++) {
      int index = (int) (ofGetElapsedTimef() * 30 + k * 4) % maxLength;
      for (int i = 0; i < groups->at(j).size() - 1; i++) {
        ofMesh* mesh1 = groups->at(j)[i];
        ofMesh* mesh2 = groups->at(j)[i + 1];
        if (index < mesh1->getNumVertices() && index < mesh2->getNumVertices()) {
          ofPoint p1 = mesh1->getVertex(index);
          ofPoint p2 = mesh2->getVertex(index);
          if (p1.distance(p2) < 100) {
            ofDrawLine(p1, p2);
          }
        }
      }
    }
    

  }
}