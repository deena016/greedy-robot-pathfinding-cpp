#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include "greedy_robot.h"
#include "test.h"
using namespace std;


RobotTest::RobotTest(int md, int rx, int ry, int tx, int ty,
                     int ex, string file_name)
	: max_dist(md), rx(rx), ry(ry), tx(tx), ty(ty),
	  expectedRoutes(ex), testDataFile(file_name) {}

bool RobotTest::Result() {
	return testResult;
}

bool RobotTest::Run() {
	testResult = true;

	set<string> userResults = GreedyRobot(max_dist, rx, ry, tx, ty);

	string msg = "";
	if (expectedRoutes != userResults.size()) {
		testResult = false;
		msg = "Incorrect number of paths: " + to_string(userResults.size());
		msg += ", expected: " +to_string(expectedRoutes);
	} else {
		msg = "Correct number of paths: " + to_string(expectedRoutes);
	}
	details.push_back(msg);

    // Optional: if result file included, validate paths generated
	if (testDataFile != "") {

		ifstream ifs(testDataFile);
		if (!ifs.is_open()) {
			throw runtime_error("Could not open file: " + testDataFile);
		}
		string path;
		set<string> correctPaths;
		while (ifs >> path) {
			auto insertRes = correctPaths.insert(path);
			if  (!insertRes.second) {
				testResult = false;
				details.push_back("Duplicate path listed: " +  path);
			}
		}
		testResult = testResult && validatePaths(correctPaths, userResults);
	}

	testRun = true;
	return testResult;
}

bool RobotTest::validatePaths(set<string> correctPaths, set<string> resultPaths) {
	bool testResult = true;

	if (correctPaths.size() > 1) {
		for (string cp : correctPaths) {
			if (!resultPaths.count(cp)) {
				testResult = false;
				details.push_back("Missing valid path: " + cp);
			}
		}
	}

	for (string rp : resultPaths) {
		if (!correctPaths.count(rp)) {
			testResult = false;
			details.push_back("Generated invalid path: " + rp);
		}
	}
	if (testResult) {
		details.push_back("All paths validated");
	}

	return testResult;
}

void RobotTest::PrintDescription() {
	printf("Max distance: %i\n", max_dist);
	printf("Robot location: (%i, %i)\n", rx, ry);
	printf("Treasure location: (%i, %i)\n", tx, ty);
	if (testDataFile == ""){
	    cout << "List of routes not validated." << endl;
	} else {
	    cout << "Correct route data from: " << testDataFile << endl;
	}
}

bool RobotTest::PrintResults(bool fullDetails) {
	if (!testRun) {
		cout << "Test has not been executed." << endl;
		return false;
	}
	cout << "TEST " << (testResult ? "PASSED" : "FAILED") << endl;
	if (fullDetails) {
		for (string s : details) {
			cout << s << endl;
		}
	}
	return testResult;
}
