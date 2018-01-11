//
//  ModeGroup.cpp
//  Mask Test
//
//  Created by Alex on 1/11/18.
//
//

#include "ModeGroup.hpp"

void ModeGroup::draw() {
  for (auto mode : modes) {
    mode->draw();
  }
}

void ModeGroup::drawUI() {
  for (auto mode : modes) {
    mode->drawUI();
  }
}

void ModeGroup::mouseMoved(float x, float y) {
  for (auto mode : modes) {
    mode->mouseMoved(x, y);
  }
}

void ModeGroup::mouseDragged(float x, float y) {
  for (auto mode : modes) {
    mode->mouseDragged(x, y);
  }
}

void ModeGroup::mousePressed(float x, float y) {
  for (auto mode : modes) {
    mode->mousePressed(x, y);
  }
}

void ModeGroup::mouseReleased(float x, float y) {
  for (auto mode : modes) {
    mode->mouseReleased(x, y);
  }
}

void ModeGroup::keyPressed(int key) {
  for (auto mode : modes) {
    mode->keyPressed(key);
  }
}

void ModeGroup::keyReleased(int key) {
  for (auto mode : modes) {
    mode->draw();
  }
}
