#ifndef CactusPulse_hpp
#define CactusPulse_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class CactusPulse : public Mode {
public:
  CactusPulse(ofApp* app_, vector<vector<ofMesh*>>* groups_) : Mode(app_, "CACTUS PULSE"), groups(groups_) {}
  void draw();
  void setLineWeight(float lineWeight_) { lineWeight = lineWeight_; }
  void setPulseSparsity(float pulseSparsity_) { pulseSparsity = pulseSparsity_; }
  
private:
  float lineWeight = 10;
  float pulseSparsity = 5;
  vector<vector<ofMesh*>>* groups;
  float t;
};

#endif
