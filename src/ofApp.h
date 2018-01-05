#pragma once

#include "ofMain.h"
#include <stdio.h>
#include "Mode.hpp"
#include "DrawLinesMode.hpp"
#include "MaskMode.hpp"

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
  
  vector<ofPoint>* getPoints() { return &points; }
  vector<vector<ofMesh*>>* getCacti() { return &cacti; }

private:
  void smooth(ofMesh* mesh);
  void addNewLine();
  void addNewCactus();
  void save(ofMesh* mesh, string filename);
  void load(ofMesh* mesh, string filename);
  
  vector<Mode*> modes;
  int currentMode = 0;
  
  ofFbo mask;
  ofFbo canvas;
  vector<ofPoint> points;
  vector<vector<ofMesh*>> cacti;
  ofImage image;
};
