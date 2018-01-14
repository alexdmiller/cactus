#ifndef Crawler_hpp
#define Crawler_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class Crawler : public Mode {
public:
  Crawler(ofApp* app_, vector<vector<ofMesh*>>* groups_) : Mode(app_, "CRAWLER"), groups(groups_) {}
  void draw();
  void setLineWeight(float lineWeight_) { lineWeight = lineWeight_; }
  void setPulseSparsity(float pulseSparsity_) { pulseSparsity = pulseSparsity_; }
  void setWobbleAmount(float wobbleAmount_) { wobbleAmount = wobbleAmount_; }

private:
  vector<vector<ofMesh*>>* groups;
  float t;
  float lineWeight = 10;
  float pulseSparsity = 5;
  float wobbleAmount = 3;

};

#endif
