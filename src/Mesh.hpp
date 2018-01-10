#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class Mesh : public Mode {
public:
  Mesh(ofApp* app_, vector<vector<ofMesh*>>* groups_) : Mode(app_, "MESH"), groups(groups_) {}
  void draw();
  
private:
  vector<vector<ofMesh*>>* groups;
};

#endif
