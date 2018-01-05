//
//  CactusMode.hpp
//  Mask Test
//
//  Created by Alex on 1/4/18.
//
//

#ifndef MaskMode_hpp
#define MaskMode_hpp

#include <stdio.h>
#include "Mode.hpp"

class ofApp;

class MaskMode : public Mode {
public:
  MaskMode() : Mode("MASK") {}
  void draw();
  void drawUI();
  void mouseMoved(float x, float y);
  void mouseDragged(float x, float y);
  void mousePressed(float x, float y);
  void mouseReleased(float x, float y);
  void keyPressed(int key);
};

#endif /* CactusMode_hpp */
