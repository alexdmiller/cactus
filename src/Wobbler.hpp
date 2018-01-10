#ifndef Wobbler_hpp
#define Wobbler_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class Wobbler : public Mode {

public:
  Wobbler(ofApp* app_, vector<vector<ofMesh*>>* groups_) : Mode(app_, "WOBBLER"), groups(groups_) {}
  void draw();
  
private:
  vector<vector<ofMesh*>>* groups;
};

#endif
