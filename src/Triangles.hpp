#ifndef Triangles_hpp
#define Triangles_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class Triangles : public Mode {
public:
  Triangles(ofApp* app_, ofMesh* mesh_) : Mode(app_, "TRIANGLES"), mesh(mesh_) {}
  void draw();
  
private:
  ofMesh* mesh;
  float horizontalT;
  float verticalT;
};

#endif
