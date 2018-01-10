//
//  Triangles.cpp
//  Mask Test
//
//  Created by Alex on 1/9/18.
//
//

#include "Triangles.hpp"

void Triangles::draw() {
  auto triangles = mesh->getUniqueFaces();
  
  ofFill();
  for (int i = 0; i < triangles.size(); i++) {
    ofSetColor(ofFloatColor(ofMap(sin((float) i / 5 + ofGetElapsedTimef()), -1, 1, 0, 1)));
    ofMeshFace tri = triangles.at(i);
    ofDrawTriangle(tri.getVertex(0), tri.getVertex(1), tri.getVertex(2));
  }
}
