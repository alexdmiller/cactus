#ifndef CactusPulse_hpp
#define CactusPulse_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class CactusPulse : public Mode {
public:
  CactusPulse(ofApp* app_, vector<vector<ofMesh*>>* groups_) : Mode(app_, "CACTUS PULSE"), groups(groups_) {}
  void draw();
  
private:
  vector<vector<ofMesh*>>* groups;
  float t;
};

#endif
