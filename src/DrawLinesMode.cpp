//
//  CactusMode.cpp
//  Mask Test
//
//  Created by Alex on 1/4/18.
//
//

#include "DrawLinesMode.hpp"


void DrawLinesMode::draw() {
  // Draw pulsing lines
  int count = 0;
  for (int j = 0; j < groups->size(); j++) {
    ofMesh* firstMesh = groups->at(j)[0];

    for (int i = 0; i < groups->at(j).size(); i++) {
      ofMesh* mesh = groups->at(j)[i];

      if (j == selectedGroup && (i == selectedLine || selectedLine == -1)) {
        ofSetColor(0, 255, 255);
      } else {
        ofSetColor(255, 255, 255);
      }

      for (int j = 0; j < (int) mesh->getNumVertices() - 1; j++) {
        ofDrawLine(mesh->getVertex(j), mesh->getVertex(j + 1));
      }
    }
    
    ofDrawBitmapString(ofToString(j), firstMesh->getVertex(0));
  }

}

void DrawLinesMode::drawUI() {
  ofDrawBitmapString("group = " + ofToString(selectedGroup), 0, 0);
  ofDrawBitmapString("line = " + ofToString(selectedLine), 0, 20);
  
  ofDrawBitmapString("C   new group\n"
                     "L   new line\n"
                     "N   next group\n"
                     ">   next line",
                     0, 40);
}

void DrawLinesMode::mouseMoved(float x, float y) {
  
}

void DrawLinesMode::mouseDragged(float x, float y) {
  if (selectedLine >= 0) {
    groups->at(selectedGroup)[selectedLine]->addVertex(ofPoint(x, y));
  }
}

void DrawLinesMode::mousePressed(float x, float y) {
//  if (cacti[selectedCactus].size() == 0) {
//    //      addNewLine();
//    //    }
}

void DrawLinesMode::mouseReleased(float x, float y) {
  if (selectedGroup >= 0 && selectedLine >= 0) {
    smooth(groups->at(selectedGroup)[selectedLine]);
  }
}

void DrawLinesMode::keyPressed(int key) {
  if (key == 99) {
    vector<ofMesh*> group;
    groups->push_back(group);
    selectedGroup = groups->size() - 1;
    selectedLine = -1;
  } else if (key == 108) {
    ofMesh* mesh = new ofMesh();
    groups->at(selectedGroup).push_back(mesh);
    selectedLine = groups->at(selectedGroup).size() - 1;
  } else if (key == 358) {
    selectedLine = (selectedLine + 1) % groups->at(selectedGroup).size();
  } else if (key == 356) {
    selectedLine = (selectedLine - 1) % groups->at(selectedGroup).size();
  } else if (key == 110) {
    selectedGroup = (selectedGroup - 1) % groups->size();
    selectedLine = -1;
  }
}

void DrawLinesMode::smooth(ofMesh* mesh) {
  int original = mesh->getNumVertices();
  int removed = 0;
  for (int i = mesh->getNumVertices() - 1; i > 0; i--) {
    ofPoint p1 = mesh->getVertex(i);
    ofPoint p2 = mesh->getVertex(i - 1);
    if (p1.distance(p2) < 5) {
      ofPoint points[] = {p1, p2};
      ofPoint avg;
      avg.average(points, 2);
      
      mesh->removeVertex(i - 1);
      mesh->setVertex(i, avg);
      removed++;
    }
  }
}