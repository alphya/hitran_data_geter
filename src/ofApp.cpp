#include "ofApp.h"
#include <fstream>
/*
    string中の特定文字列をstringで置換する
*/
std::string replace_string
      (
            std::string String1   // 置き換え対象
            , std::string String2   // 検索対象
            , std::string String3   // 置き換える内容
      )
{
   std::string::size_type  Pos( String1.find( String2 ) );

   String1.replace( Pos, String2.length(), String3 );

   return String1;
}

//--------------------------------------------------------------
void ofApp::setup(){


   program = Py_DecodeLocale("HITRAN DATA GETTER", NULL);
   if (program == NULL) {
      fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
      //exit(1);
   }
   Py_SetProgramName(program);  /* optional but recommended */
   Py_Initialize();

   gui = std::make_unique<ofxDatGui>(100, 180);
   gui->setWidth(300);
   gui->setTheme(new ofxDatGuiThemeWireframe());


   ofSetWindowTitle("HITRAN'S DATA GETTER");


   gui->addHeader(":: Please Input Data ::", false);

   gui->addTextInput("Molecules ID","");
   gui->addTextInput("Isotropic ID","");
   gui->addTextInput("nu_min [cm^-1]", "");
   gui->addTextInput("nu_max [cm^-1]","");
   gui->addButton("Click here when you are finished");


   gui->onButtonEvent([&](ofxDatGuiButtonEvent e)
   {
      std::ifstream ifs("python_script_template.txt");
      std::string str((std::istreambuf_iterator<char>(ifs)),
                           std::istreambuf_iterator<char>());
      ifs.close();

      str = replace_string(str, "NAME", string("\"") + gui->getTextInput("Molecules ID")->getText() + "_"
                     + gui->getTextInput("Isotropic ID")->getText() + string("\""));
      str = replace_string(str, "MOLECULES_ID", gui->getTextInput("Molecules ID")->getText());
      str = replace_string(str, "ISOTROPIC_ID", gui->getTextInput("Isotropic ID")->getText());
      str = replace_string(str, "SPECTRUM_BEGIN", gui->getTextInput("nu_min")->getText());
      str = replace_string(str, "SPECTRUM_END", gui->getTextInput("nu_max")->getText());

      PyRun_SimpleString(str.c_str());

   });



   // Fonts
   ofTrueTypeFont::setGlobalDpi(72);

   verdana.load("verdana.ttf", 23); // フォントのデータを指定する
   verdana.setLineHeight(24);       // 行間を指定する
   verdana.setLetterSpacing(1.0);   // 文字間を指定する

   verdana2.load("verdana.ttf", 12); // フォントのデータを指定する
   verdana2.setLineHeight(24);       // 行間を指定する
   verdana2.setLetterSpacing(1.0);   // 文字間を指定する

   description1.load("description1.png");
   description2.load("description2.png");
   description3.load("description3.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
   ofColor colorOne(255, 255, 240);
   ofColor colorTwo(205, 205, 199);

   ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);

   ofSetColor(107, 101, 93); // 文字色を指定
   verdana.drawString("HITRAN DATA GETTER", 100, 80); // 文字とポジションを指定して描画

   ofSetColor(155,146,135);
   verdana2.drawString("Welcome to HITRAN DATA GETTER. This program gets data"
                       "from HITRAN and outputs it to a .csv file. The .csv file "
                       "contains information \non transition wavenumber, line intensity,"
                       "and quantum number changes. When using this program, please connect to the Internet.", 100, 120);

   ofSetColor(255, 255, 255);
   //description1.draw(600, 180, 200, 200);
   //description2.draw(830, 180, 200, 200);
   //description3.draw(100, 350, 560, 450);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}