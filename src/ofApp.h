#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include <memory>
#include <vector>
#define PY_SSIZE_T_CLEAN
#include <Python.h>

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		~ofApp()
      {
         Py_FinalizeEx();
         PyMem_RawFree(program);
      }

   std::unique_ptr<ofxDatGui> gui;
   wchar_t *program;
   ofTrueTypeFont verdana;
   ofTrueTypeFont verdana2;

   ofImage description1;
   ofImage description2;
   ofImage description3;
};
