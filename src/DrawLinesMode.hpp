#ifndef DrawLinesMode_hpp
#define DrawLinesMode_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class DrawLinesMode : public Mode {
public:
  DrawLinesMode(ofApp* app_, vector<vector<ofMesh*>>* groups_) : Mode(app_, "LINES"), groups(groups_) {}
  void draw();
  void drawUI();
  void mouseMoved(float x, float y);
  void mouseDragged(float x, float y);
  void mousePressed(float x, float y);
  void mouseReleased(float x, float y);
  void keyPressed(int key);

private:
  void smooth(ofMesh* mesh);

  int selectedLine = -1;
  int selectedGroup = -1;
  
  vector<vector<ofMesh*>>* groups;
};

#endif
