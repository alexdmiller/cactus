//
//  CactusMode.cpp
//  Mask Test
//
//  Created by Alex on 1/4/18.
//
//

#include "DrawLinesMode.hpp"


void DrawLinesMode::draw() {
}

void DrawLinesMode::drawUI() {
  ofDrawBitmapString("HELLO", 0, 0);
}

void DrawLinesMode::mouseMoved(float x, float y) {
  
}

void DrawLinesMode::mouseDragged(float x, float y) {
  if (selectedLine >= 0) {
    lines->at(selectedCactus)[selectedLine]->addVertex(ofPoint(x, y));
  }
}

void DrawLinesMode::mousePressed(float x, float y) {
  cout << "DRAW LINES CLICK\n";
//  if (cacti[selectedCactus].size() == 0) {
//    //      addNewLine();
//    //    }
}

void DrawLinesMode::mouseReleased(float x, float y) {
  //  if (selectedLine >= 0 && mode == 1) {
  //    smooth(cacti[selectedCactus][selectedLine]);
  //  }
}

void DrawLinesMode::keyPressed(int key) {
  
}