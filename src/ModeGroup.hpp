#ifndef ModeGroup_hpp
#define ModeGroup_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class ModeGroup : public Mode {
public:
  ModeGroup(ofApp* app_, string name_, vector<Mode*> modes_) : Mode(app_, name_), modes(modes_) {}
  void draw();
  void drawUI();
  void mouseMoved(float x, float y);
  void mouseDragged(float x, float y);
  void mousePressed(float x, float y);
  void mouseReleased(float x, float y);
  void keyPressed(int key);
  void keyReleased(int key);
  
private:
  vector<Mode*> modes;
};

#endif
