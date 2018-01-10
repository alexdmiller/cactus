#include "ofApp.h"
#include "DrawLinesMode.hpp"
#include "MaskMode.hpp"
#include "CactusPulse.hpp"
#include "Crawler.hpp"
#include "Mesh.hpp"
#include "Wobbler.hpp"
#include "MeshEditMode.hpp"
#include "Triangles.hpp"
#include <unordered_set>
#include <utility>

void ofApp::setup(){
  modes.push_back(new MeshEditMode(this, &mesh));
  modes.push_back(new Triangles(this, &mesh));
  modes.push_back(new Crawler(this, &hanging));
  modes.push_back(new DrawLinesMode(this, &cacti));
  modes.push_back(new MaskMode(this));
  modes.push_back(new CactusPulse(this, &cacti));
  modes.push_back(new Crawler(this, &cacti));
  modes.push_back(new Mesh(this, &cacti));
  modes.push_back(new Wobbler(this, &cacti));
  
  
  ofToggleFullscreen();
  
  canvas.allocate(ofGetWidth(), ofGetHeight());
  mask.allocate(ofGetWidth(), ofGetHeight());
  
  image.load("pic.jpg");
  
  int j = 0;
  while (ofFile::doesFileExist("group_" + to_string(j) + "_mesh_0")) {
    vector<ofMesh*> group;
    int i = 0;
    while (ofFile::doesFileExist("group_" + to_string(j) + "_mesh_" + to_string(i))) {
      cout<<"group_" + to_string(j) + "_mesh_" + to_string(i) + "\n";
      ofMesh* m = new ofMesh();
      load(m, "group_" + to_string(j) + "_mesh_" + to_string(i));
      group.push_back(m);
      i++;
    }
    cacti.push_back(group);
    j++;
  }
  
  if (ofFile::doesFileExist("mesh")) {
    load(&mesh, "mesh");
  }
}

void ofApp::update() {
  
}

void ofApp::drawUI() {
  for (int i = 0; i < points.size(); i++) {
    ofNoFill();
    ofSetColor(255, 0, 0, 255);
    ofDrawCircle(points.at(i), 10);
  }

}

void ofApp::draw() {
  ofPoint currentMousePosition(ofGetMouseX(), ofGetMouseY());
  targetMouseVelocity.set(currentMousePosition - lastMousePosition);
  lastMousePosition.set(currentMousePosition);
  
  ofPoint delta(targetMouseVelocity - mouseVelocity);
  mouseVelocity += delta / 10;
  
  CGSetLocalEventsSuppressionInterval(0);
  if (currentMousePosition.y <= 0) {
    CGPoint point;
    point.x = currentMousePosition.x;
    point.y = ofGetHeight() - 2;
    CGWarpMouseCursorPosition(point);
    cout << "top warp\n";
  } else if (currentMousePosition.y >= ofGetHeight() - 1) {
    CGPoint point;
    point.x = currentMousePosition.x;
    point.y = 1;
    CGWarpMouseCursorPosition(point);
    cout << "bottom warp\n";
  }
  
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
  
  if (showUI) {
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 50, 50);
  //  ofDrawBitmapString(ofToString(count) + " vertices", 50, 70);
    for (int i = 0; i < modes.size(); i++) {
      ofDrawBitmapString(ofToString((i + 1)) + "\t" + modes[i]->getName(), 50, 90 + i * 20);
    }
    
    ofPushMatrix();
    ofTranslate(50, 90 + modes.size() * 20 + 30);
    ofDrawBitmapString(modes[currentMode]->getName(), 0, 0);
    ofSetColor(255, 255, 255);
    ofSetLineWidth(1);
    ofDrawLine(0, 10, 200, 10);
    ofTranslate(0, 30);
    modes[currentMode]->drawUI();
    ofPopMatrix();
  }
}

void ofApp::keyPressed(int key) {
  if (key >= 49 && key <= 60) {
    if (key - 49 < modes.size()) {
      currentMode = key - 49;
    }
  } else if (key == 32) {
    showUI = !showUI;
  } else {
    modes[currentMode]->keyPressed(key);
  }
}

void ofApp::keyReleased(int key){
  modes[currentMode]->keyReleased(key);
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

void ofApp::mouseReleased(int x, int y, int button) {
  modes[currentMode]->mouseReleased(x, y);
}

void ofApp::exit() {
  for (int j = 0; j < cacti.size(); j++) {
    for (int i = 0; i < cacti[j].size(); i++) {
      save(cacti[j][i], "group_" + to_string(j) + "_mesh_" + to_string(i));
    }
  }
  
  save(&mesh, "mesh");
}

void ofApp::save(ofMesh* mesh, string filename) {
  ofFile file;
  file.open(filename, ofFile::WriteOnly);
  for (int i = 0; i < mesh->getNumVertices(); i++) {
    file << mesh->getVertex(i).x << " " << mesh->getVertex(i).y << "\n";
  }
  file << "indices\n";
  for (int i = 0; i < mesh->getNumIndices(); i++) {
    file << mesh->getIndex(i) << "\n";
  }
  file.close();
}

void ofApp::load(ofMesh* mesh, string filename) {
  auto lines = ofSplitString(ofBufferFromFile(filename).getText(), "\n");
  
  int lineNumber = 0;
  while (lineNumber < lines.size() &&
         !lines.at(lineNumber).empty() &&
         lines.at(lineNumber) != "indices") {
    auto coords = ofSplitString(lines.at(lineNumber), " ");
    mesh->addVertex(ofPoint(ofToFloat(coords.at(0)), ofToFloat(coords.at(1))));
    lineNumber++;
  }
  
  lineNumber++;
  
  while (lineNumber < lines.size() &&
         !lines.at(lineNumber).empty()) {
    mesh->addIndex(ofToFloat(lines.at(lineNumber)));
    lineNumber++;
  }
}

ofPoint ofApp::getMouseVelocity() {
  return mouseVelocity;
}

void ofApp::transformMeshToGroups() {
  hanging.clear();

  unordered_set<pair<int, int>,  pair_hash> edges;
  for (int i = 0; i < mesh.getNumIndices(); i += 3) {
    for (int j = 0; j < 3; j++) {
      pair<int, int> edge(mesh.getIndex(i + j), mesh.getIndex(i + ((j + 1) % 3)));
      pair<int, int> edgeSwapped(edge.second, edge.first);
      if (edges.find(edge) == edges.end() && edges.find(edgeSwapped) == edges.end()) {
        edges.insert(edge);
      }
    }
  }
  
  vector<ofMesh*> group;
  for (const auto& edge : edges) {
    ofMesh* m = new ofMesh();
    ofPoint p1 = mesh.getVertex(edge.first);
    ofPoint p2 = mesh.getVertex(edge.second);
    ofPoint delta = p2 - p1;
    delta.normalize();
    int steps = p1.distance(p2) / 5;
    for (int i = 0; i < steps; i++) {
      m->addVertex(p1 + delta * 5 * i);
    }
    group.push_back(m);
  }
  
  hanging.push_back(group);
}





