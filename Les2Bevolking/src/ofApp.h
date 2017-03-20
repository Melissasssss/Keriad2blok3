#pragma once

#include "SQLiteCpp.h"
#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();

	void update();

	void draw();

private:
	SQLite::Database* db;
	int selectedYear;
	float pctSingle;
	float pctMultiple;

};
