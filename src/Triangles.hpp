#ifndef Triangles_hpp
#define Triangles_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class Triangles : public Mode {
public:
  Triangles(ofApp* app_, vector<ofMesh*>* meshes_) : Mode(app_, "TRIANGLES"), meshes(meshes_) {}
  void draw();
  
private:
  vector<ofMesh*>* meshes;
  float horizontalT;
  float verticalT;
};

#endif
