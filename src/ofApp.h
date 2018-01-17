#pragma once

#include "ofMain.h"
#include <stdio.h>
#include "Mode.hpp"

struct pair_hash {
  inline std::size_t operator()(const std::pair<int,int> & v) const {
    return v.first*31+v.second;
  }
};

class ofApp : public ofBaseApp {

public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y );
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void exit();
  void drawUI();
  void transformMeshToGroups();
  ofPoint getMouseVelocity();

private:
  void save(ofMesh* mesh, string filename);
  void load(ofMesh* mesh, string filename);
  
  vector<Mode*> modes;
  int currentMode = 0;
  
  ofFbo mask;
  ofFbo canvas;
  vector<ofPoint> points;
  vector<vector<ofMesh*>> cacti;
  vector<vector<ofMesh*>> hanging;
  vector<ofMesh*> meshes;
  ofImage image;
  bool showUI = true;
  
  ofPoint lastMousePosition;
  ofPoint mouseVelocity;
  ofPoint targetMouseVelocity;
};
