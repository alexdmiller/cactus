#ifndef Crawler_hpp
#define Crawler_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class Crawler : public Mode {
public:
  Crawler(ofApp* app_, vector<vector<ofMesh*>>* groups_) : Mode(app_, "CRAWLER"), groups(groups_) {}
  void draw();
  
private:
  vector<vector<ofMesh*>>* groups;
  float t;
};

#endif
