#include "ofApp.h"

void ofApp::setup() {
	db = new SQLite::Database("data/huishoudens.sqlite");
}

void ofApp::update() {
	/*
	// voorbeeld: haal alle waardes uit de tabel
	SQLite::Statement query(*db, "SELECT * FROM huish");
	while (query.executeStep()) {
	ofLog() << query.getColumn("year") <<
	" " << query.getColumn("hh_total") << endl;
	}
	*/

	/*
	// voorbeeld: stuur een variabele uit je programma naar de database
	SQLite::Statement query(*db, "SELECT * FROM huish WHERE year=?");
	for (int year = 2012; year <= 2016; year++) {
	query.bind(1, year); // vervang 1e vraagteken door de waarde van de variabele
	if (query.executeStep()) {
	ofLog() << query.getColumn("year") <<
	" " << query.getColumn("hh_total") << endl;
	}
	query.reset();
	}
	*/

	int year = ofMap(ofGetMouseX(), 0, ofGetWidth() - 100, 2012, 2016, true);

	if (year != selectedYear) {
		selectedYear = year;
		// een statement met een gewone, en twee *berekende* kolommen
		string statement = "SELECT hh_total, \
                            (hh_single*1.0/ hh_total * 100), \
                            (hh_multiple*1.0/hh_total * 100) \
                            FROM huish \
                            WHERE year = ?";

		SQLite::Statement query(*db, statement);
		query.bind(1, selectedYear); // vervang 1e vraagteken door de waarde van de variabele
		if (query.executeStep()) {
			pctSingle = query.getColumn(1).getDouble();
			pctMultiple = query.getColumn(2).getDouble();
			ofLog() << selectedYear << " " << pctSingle << " " << pctMultiple << endl;
		}
		query.reset();
	}
}

void ofApp::draw() {
	ofSetBackgroundColor(0, 0, 0);
	ofDrawCircle(100,100,pctMultiple);
	ofNoFill();
	ofDrawBitmapString(selectedYear, 100, 100);
	ofDrawCircle(500, 100, pctSingle);
}