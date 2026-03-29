/*
main.cpp

This program allows the user to test the GreedyRobot function.
The user can either:
(A) Enter custom robot and treasure coordinates, or
(B) Run a predefined test suite to verify correctness.

Author: Deena Qannan
*/

#include <iostream>
#include <set>
#include <fstream>
#include <vector>
#include "greedy_robot.h"
#include "test.h"
using namespace std;

void RunSingleRoute() {
    // Take user inputs
	cout << "Enter the route parameters:" << endl;
	int max_dist, robot_x, robot_y, t_x, t_y;
	cout << "max_distance: ";
	cin >> max_dist;
	cout << "robot_x: ";
	cin >> robot_x;
	cout << "robot_y: ";
	cin >> robot_y;
	cout << "treasure_x: ";
	cin >> t_x;
	cout << "treasure_y: ";
	cin >> t_y;
	cout << endl;

    // Analyze the routes
	auto routes = GreedyRobot(max_dist, robot_x, robot_y, t_x, t_y);

    // Output results
	cout << "Num routes: " << routes.size() << endl;
	if (routes.size() > 0) {
		cout << "Example valid route: " << *routes.begin() << endl;
		string resultsFile = "results.txt";
		ofstream of(resultsFile);
		for (string r : routes) {
			of << r << endl;
		}
		of.close();
		cout << "Full route list in: " << resultsFile << endl;
	}
}

void RunTestSuite() {
	
	RobotTest test1 = RobotTest(2, 1, 2, 3, 5, 7, "test1.txt");
	RobotTest test2 = RobotTest(1, 3, 4, 4, 3, 2, "test2.txt");
	RobotTest test3 = RobotTest(5, 20, 12, 10, 10, 21, "test3.txt");
	// TODO: add another full test
	RobotTest test5 = RobotTest(5, -10, 100, -5, 110, 2247);
	RobotTest test6 = RobotTest(1, 1, 1, 1, 1, 1);
	RobotTest test7 = RobotTest(1, 1, 1, 1, 10, 0);
	RobotTest test8 = RobotTest(3, 14, 10, -3, 3, 2472);
	RobotTest test9 = RobotTest(2, 12, 9, -2, 2, 36);
	RobotTest test10 = RobotTest(1, 0, 0, -12, -12, 2);
	// TODO: add 2+ simplified tests 

	vector<RobotTest> tests = { test1, test2, test3, 
	        test5, test6, test7, test8, test9, test10 };
	        
    int passCount = 0;
	for (RobotTest t: tests) {
		t.Run();
		t.PrintDescription();
		t.PrintResults();
		passCount += (int)t.Result();
		cout << endl;
	}
	
	printf("Tests: %d, PASSED: %d, FAILED: %d\n",
	    tests.size(), passCount, tests.size() - passCount);
}

int main(int argc, char **argv) {

	cout << "Do you want to: " << endl;
	cout << "(A) Evaluate a single map?" << endl;
	cout << "(B) Run the test suite?" << endl;

	char userChoice;
	cin >> userChoice;
	cout << endl;
	switch (userChoice) {
	case 'A':
	case 'a':
		RunSingleRoute();
		break;
	case 'B':
	case 'b':
		RunTestSuite();
		break;
	default:
		cout << "Invalid option selected." << endl;
	}

}