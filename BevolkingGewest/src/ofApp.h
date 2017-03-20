#pragma once

#include "ofMain.h"
#include "SQLiteCpp.h"

class ofApp : public ofBaseApp {

    public:
        void setup();

        void update();

        void draw();

        void keyPressed(int key);

        void keyReleased(int key);

        void mouseMoved(int x, int y);

		//void ofImage(int newWidth, int newHeight);

    private:
        SQLite::Database* db;
        int selectedYear = 1900;

        int total;
        int north;
        int east;
        int south;
        int west;

		ofImage plaatje;
};
