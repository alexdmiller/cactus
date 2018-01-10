#ifndef MeshEditMode_hpp
#define MeshEditMode_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class MeshEditMode : public Mode {
public:
  MeshEditMode(ofApp* app_, ofMesh* mesh_) : Mode(app_, "MESH EDIT"), mesh(mesh_) {
    mesh->setMode(OF_PRIMITIVE_TRIANGLES);
  }

  void draw();
  void drawUI();
  void mouseMoved(float x, float y);
  void mouseDragged(float x, float y);
  void mousePressed(float x, float y);
  void mouseReleased(float x, float y);
  void keyPressed(int key);
  void keyReleased(int key);
  
private:
  ofMesh* mesh;
  int selectedIndex;
  bool shiftDown;
};

#endif
