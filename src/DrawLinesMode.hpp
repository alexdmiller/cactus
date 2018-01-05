#ifndef DrawLinesMode_hpp
#define DrawLinesMode_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class DrawLinesMode : public Mode {
public:
  DrawLinesMode(vector<vector<ofMesh*>>* lines_) : Mode("LINES"), lines(lines_) {}

  void draw();
  void drawUI();
  void mouseMoved(float x, float y);
  void mouseDragged(float x, float y);
  void mousePressed(float x, float y);
  void mouseReleased(float x, float y);
  void keyPressed(int key);

private:
  int selectedLine = -1;
  int selectedCactus = -1;
  
  vector<vector<ofMesh*>>* lines;
};

#endif
