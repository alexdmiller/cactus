#ifndef Dots_hpp
#define Dots_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class Dots : public Mode {
  
public:
  Dots(ofApp* app_, vector<vector<ofMesh*>>* groups_) : Mode(app_, "DOTS"), groups(groups_) {}
  void draw();
  
private:
  vector<vector<ofMesh*>>* groups;
};

#endif
