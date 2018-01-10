//
//  Mode.hpp
//  Mask Test
//
//  Created by Alex on 1/4/18.
//
//

#ifndef Mode_hpp
#define Mode_hpp

#include <stdio.h>
#include "ofMain.h"

class ofApp;

class Mode {
public:
  Mode(ofApp* app_, string name_) : app(app_), name(name_) {}
  string getName() { return name; }
  
  virtual void draw() {};
  virtual void drawUI() {};
  virtual void mouseMoved(float x, float y) {};
  virtual void mouseDragged(float x, float y) {};
  virtual void mousePressed(float x, float y) {};
  virtual void mouseReleased(float x, float y) {};
  virtual void keyPressed(int key) {};
  virtual void keyReleased(int key) {};

protected:
  ofApp* getApp() { return app; }

private:
  string name;
  ofApp* app;
};


#endif /* Mode_hpp */
