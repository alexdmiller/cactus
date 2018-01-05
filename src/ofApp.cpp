#include "ofApp.h"

void ofApp::setup(){
  modes.push_back(new DrawLinesMode(&cacti));
  modes.push_back(new MaskMode());
  
  ofToggleFullscreen();
  
  canvas.allocate(ofGetWidth(), ofGetHeight());
  mask.allocate(ofGetWidth(), ofGetHeight());
  
  image.load("pic.jpg");
  
  int i = 0;
  while (ofFile::doesFileExist("mesh" + to_string(i))) {
    ofMesh* m = new ofMesh();
    load(m, "mesh" + to_string(i));
    //lines.push_back(m);
    i++;
  }
}

void ofApp::update(){
  
}

void ofApp::draw() {
  ofBackground(0, 0, 0);
  
  modes[currentMode]->draw();
  
//  ofPushMatrix();
//  ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
//  ofRotate(90);
//  float scale = 0.5;
//  ofTranslate(-image.getWidth() * scale / 2, -image.getHeight() * scale / 2);
//  ofSetColor(255, 255, 255, 100);
//  image.draw(ofPoint(0, 0), image.getWidth() * scale, image.getHeight() * scale);
//  
//  ofPopMatrix();
  
  canvas.begin();
  ofClear(0, 0);
  ofSetLineWidth(2);
  ofSetColor(255, 255, 255, 255);
  ofFill();
  ofRotate(20);
  for (float y = 0; y < ofGetHeight(); y += ofGetHeight() / 20) {
    float yPos = fmod(y + ofGetElapsedTimef() * 50, ofGetHeight());
    ofDrawLine(0, yPos, ofGetWidth(), yPos);
  }
  canvas.end();
  
  mask.begin();
  ofClear(0, 0);
  ofSetColor(255, 255, 255, 255);
  ofFill();
  if (points.size() > 0) {
    ofBeginShape();
    for (int i = 0; i < points.size(); i++) {
      ofVertex(points.at(i));
    }
    ofEndShape();
  }
  mask.end();
  
  canvas.getTexture().setAlphaMask(mask.getTexture());
  ofSetColor(255, 255, 255, 255);
  canvas.draw(ofPoint(0, 0));
  
  for (int i = 0; i < points.size(); i++) {
    ofNoFill();
    ofSetColor(255, 0, 0, 255);
    ofDrawCircle(points.at(i), 10);
  }
  
  // Draw pulsing lines
  int count = 0;
  for (int j = 0; j < cacti.size(); j++) {
    for (int i = 0; i < cacti[j].size(); i++) {
      ofMesh* mesh = cacti[j][i];

//      if (i == selectedLine) {
//        ofSetColor(255, 0, 0);
//      } else {
//        ofSetColor(255, 255, 255);
//      }

      ofFill();
      
      for (int j = 0; j < (int) mesh->getNumVertices() - 1; j++) {
        float w = (sin((float) i + (float) j / 5 + ofGetElapsedTimef() * 4) + 1) / 2;
        ofDrawCircle(mesh->getVertex(j), w * w * w * w * 10);
        ofDrawLine(mesh->getVertex(j), mesh->getVertex(j + 1));
        
        //ofSetLineWidth(w * w * w * 10);
        
        count++;
      }
    }
  }
  
  ofDrawBitmapString(ofToString(ofGetFrameRate()), 50, 50);
  ofDrawBitmapString(ofToString(count) + " vertices", 50, 70);
  for (int i = 0; i < 2; i++) {
    ofDrawBitmapString(ofToString((i + 1)) + "\t" + modes[i]->getName(), 50, 90 + i * 20);
  }
  
  ofPushMatrix();
  ofTranslate(50, 90 + 2 * 20 + 30);
  ofDrawBitmapString(modes[currentMode]->getName(), 0, 0);
  ofSetColor(255, 255, 255);
  ofDrawLine(0, 10, 200, 10);
  ofTranslate(0, 30);
  modes[currentMode]->drawUI();
  ofPopMatrix();
}

/*
 1    mask mode
 2    cactus mode
 C    new cactus
 L    new line
 */
void ofApp::keyPressed(int key){
  cout << key << "\n";
  if (key == 49) {
    currentMode = 0;
  } else if (key == 50) {
    currentMode = 1;
  } else {
    modes[currentMode]->keyPressed(key);
  }
}

void ofApp::keyReleased(int key){
  
}

void ofApp::mouseMoved(int x, int y ){
  modes[currentMode]->mouseMoved(x, y);
}

void ofApp::mouseDragged(int x, int y, int button) {
  modes[currentMode]->mouseDragged(x, y);
}

void ofApp::mousePressed(int x, int y, int button) {
  modes[currentMode]->mousePressed(x, y);
}

void ofApp::addNewLine() {
  ofMesh* m = new ofMesh();
  m->setMode(OF_PRIMITIVE_LINE_STRIP);
//  cacti[selectedCactus].push_back(m);
//  selectedLine = cacti[selectedCactus].size() - 1;
}

void ofApp::addNewCactus() {
  vector<ofMesh*> cactus;
  cacti.push_back(cactus);
}

void ofApp::mouseReleased(int x, int y, int button) {
  modes[currentMode]->mouseReleased(x, y);
}

void ofApp::exit() {
  for (int j = 0; j < cacti.size(); j++) {
    for (int i = 0; i < cacti[j].size(); i++) {
      save(cacti[j][i], "cactus_" + to_string(j) + "_mesh_" + to_string(i));
    }
  }
}

void ofApp::smooth(ofMesh* mesh) {
  int original = mesh->getNumVertices();
  int removed = 0;
  for (int i = mesh->getNumVertices() - 1; i > 0; i--) {
    ofPoint p1 = mesh->getVertex(i);
    ofPoint p2 = mesh->getVertex(i - 1);
    if (p1.distance(p2) < 2) {
      ofPoint points[] = {p1, p2};
      ofPoint avg;
      avg.average(points, 2);
      
      mesh->removeVertex(i - 1);
      mesh->setVertex(i, avg);
      removed++;
    }
  }
  
  cout << "removed " << removed << " out of " << original << "\n";
  cout << "final count: " << mesh->getNumVertices() << "\n";
}

void ofApp::save(ofMesh* mesh, string filename) {
  ofFile file;
  file.open(filename, ofFile::WriteOnly);
  for (int i = 0; i < mesh->getNumVertices(); i++) {
    file << mesh->getVertex(i).x << " " << mesh->getVertex(i).y << "\n";
  }
  file.close();
}

void ofApp::load(ofMesh* mesh, string filename) {
  auto lines = ofSplitString(ofBufferFromFile(filename).getText(), "\n");
  for (int i = 0; i < lines.size(); i++) {
    if (!lines.at(i).empty()) {
      auto coords = ofSplitString(lines.at(i), " ");
      mesh->addVertex(ofPoint(ofToFloat(coords.at(0)), ofToFloat(coords.at(1))));
    }
  }
}


