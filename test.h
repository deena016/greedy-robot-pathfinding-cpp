#ifndef ROBOT_TEST_H
#define ROBOT_TEST_H
#include <string>
#include <set>

class RobotTest {
public:
	RobotTest(int md, int rx, int ry, int tx, int ty, int ex,
	          std::string name = "");
	bool Run();
	void PrintDescription();
	bool PrintResults(bool fullResults = true);
	bool Result();


private:
    bool validatePaths(std::set<std::string> cp, std::set<std::string> rp);
	bool testRun = false;
	bool testResult = false;
	std::vector<std::string> details;
	
	int max_dist;
	int rx, ry, tx, ty;
	
	int expectedRoutes;
	std::string testDataFile;
};

#endif