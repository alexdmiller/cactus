#ifndef MeshEditMode_hpp
#define MeshEditMode_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class MeshEditMode : public Mode {
public:
  MeshEditMode(ofApp* app_, vector<ofMesh*>* meshes_) : Mode(app_, "MESH EDIT"), meshes(meshes_) {}
  void draw();
  void drawUI();
  void mouseMoved(float x, float y);
  void mouseDragged(float x, float y);
  void mousePressed(float x, float y);
  void mouseReleased(float x, float y);
  void keyPressed(int key);
  void keyReleased(int key);
  
private:
  vector<ofMesh*>* meshes;
  int selectedMesh = -1;
  int selectedIndex = -1;
  bool shiftDown;
};

#endif
