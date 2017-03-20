#include <SQLiteCpp/include/SQLiteCpp/Database.h>
#include "ofApp.h"

void ofApp::setup() {
	plaatje.load("mens.png");
	plaatje.resize(20, 20);
    string databasePath = ofToDataPath("bevolking.sqlite", true);
    db = new SQLite::Database(databasePath);
}

void ofApp::update() {
    int year = ofMap(ofGetMouseX(), 0, ofGetWidth() - 100, 1900, 2016, true);

    if (year != selectedYear) {
        selectedYear = year;
        string sql = "SELECT year, north, east, south, west, north+east+south+west AS total FROM bevolking WHERE year=?";

        SQLite::Statement query(*db, sql);

        query.bind(1, selectedYear); // vervang 1e vraagteken door de waarde van de variabele
        if (query.executeStep()) {
            total = query.getColumn("total").getInt();
            year = query.getColumn("year").getInt();
            north = query.getColumn("north").getInt();
            east = query.getColumn("east").getInt();
            south = query.getColumn("south").getInt();
            west = query.getColumn("west").getInt();
            ofLog() << selectedYear << " " << total << " "
                    << north << " " << east << " " << south << " " << west
                    << endl;
        }

        query.reset();
    }

}

void ofApp::draw() {
    ofBackgroundGradient(ofColor::lightGoldenRodYellow, ofColor::skyBlue);
    ofDrawCircle(ofGetWidth() / 2 * 0.5, ofGetHeight() / 2 * 0.5, west * 1.0f / total * 200);
    ofDrawCircle(ofGetWidth() / 2 * 1.5, ofGetHeight() / 2 * 0.5, east * 1.0f / total * 200);
    ofDrawCircle(ofGetWidth() / 2 * 0.5, ofGetHeight() / 2 * 1.5, north * 1.0f / total * 200);
    ofDrawCircle(ofGetWidth() / 2 * 1.5, ofGetHeight() / 2 * 1.5, south * 1.0f / total * 200);
	ofSetColor(ofColor::black);
	ofDrawBitmapString("west", ofGetWidth() / 2 * 0.5, ofGetHeight() / 2 * 0.5);
	ofDrawBitmapString("east", ofGetWidth() / 2 * 1.5, ofGetHeight() / 2 * 0.5);
	ofDrawBitmapString("north", ofGetWidth() / 2 * 0.5, ofGetHeight() / 2 * 1.5);
	ofDrawBitmapString("south", ofGetWidth() / 2 * 1.5, ofGetHeight() / 2 * 1.5);
	ofDrawBitmapString(selectedYear, 100, 100);
	ofSetColor(ofColor::white);

	plaatje.draw(ofGetWidth() / 2 * 0.5, ofGetHeight() / 2 * 0.5); //west
	plaatje.draw(ofGetWidth() / 2 * 1.5, ofGetHeight() / 2 * 0.5); //east
	plaatje.draw(ofGetWidth() / 2 * 0.5, ofGetHeight() / 2 * 1.5); //north
	plaatje.draw(ofGetWidth() / 2 * 1.5, ofGetHeight() / 2 * 1.5); //south

	//+1 poppetje west
	if (west >=6000 && west <= 7000) {
		plaatje.draw((ofGetWidth() / 2 * 0.5)+20, ofGetHeight() / 2 * 0.5);
	}
	if (west >= 7001 && west <= 8000) {
		plaatje.draw((ofGetWidth() / 2 * 0.5) + 20, ofGetHeight() / 2 * 0.5);
		plaatje.draw((ofGetWidth() / 2 * 0.5) + 40, ofGetHeight() / 2 * 0.5);
	}
	if (west >= 8001 && west <= 9000) {
		plaatje.draw((ofGetWidth() / 2 * 0.5) + 20, ofGetHeight() / 2 * 0.5);
		plaatje.draw((ofGetWidth() / 2 * 0.5) + 40, ofGetHeight() / 2 * 0.5);
		plaatje.draw((ofGetWidth() / 2 * 0.5) + 60, ofGetHeight() / 2 * 0.5);

	}
	if (west >= 9001 && west <= 10000) {
		plaatje.draw((ofGetWidth() / 2 * 0.5) + 20, ofGetHeight() / 2 * 0.5);
		plaatje.draw((ofGetWidth() / 2 * 0.5) + 40, ofGetHeight() / 2 * 0.5);
		plaatje.draw((ofGetWidth() / 2 * 0.5) + 60, ofGetHeight() / 2 * 0.5);
		plaatje.draw((ofGetWidth() / 2 * 0.5) + 80, ofGetHeight() / 2 * 0.5);

	}
	if (west >= 9001 && west <= 10000) {
		plaatje.draw((ofGetWidth() / 2 * 0.5) + 100, ofGetHeight() / 2 * 0.5);
	}
}



void ofApp::keyPressed(int key) {

}

void ofApp::keyReleased(int key) {

}

void ofApp::mouseMoved(int x, int y) {

}