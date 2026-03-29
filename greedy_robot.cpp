/*
greedy_robot.cpp

This file implements the GreedyRobot function that finds all possible
shortest paths from the robot's starting position to the treasure.

The robot can move North, South, East, or West, but:
- It must always move closer to the treasure.
- It cannot move in the same direction more than max_distance times in a row.

A recursive helper function builds each valid path step by step.
All valid paths are stored in a set<string> to prevent duplicates.

Author: Deena Qannan

*/
#include <iostream>
#include <cmath>
#include "greedy_robot.h"
using namespace std;


// Helper function to recursively build all valid shortest paths.
void helper (int max_distance, int remH, int remV, char hDir, char vDir,
             string path, char lastDir, int repeatCount, set<string>& results)
{
	// Base case: no moves remaining (reached treasure)
	if (remH == 0 && remV == 0) {
		results.insert(path);
		return;
	}

	// Try horizontal move (E or W)
	if (remH > 0) {
		if (lastDir != hDir || repeatCount < max_distance) {
			int newRepeat = (lastDir == hDir) ? repeatCount + 1 : 1;
			
			helper(max_distance, remH - 1, remV, hDir, vDir, path + hDir,
			       hDir, newRepeat, results);
		}
	}

	// Try vertical move (N or S)
	if (remV > 0) {
		if (lastDir != vDir || repeatCount < max_distance) {
			int newRepeat = (lastDir == vDir) ? repeatCount + 1 : 1;
			
			helper(max_distance, remH, remV - 1, hDir, vDir, path + vDir,
			       vDir, newRepeat, results);
		}
	}
}


// GreedyRobot: Calculate all unique shortest valid routes
set<string> GreedyRobot(int max_distance, int rx, int ry, int tx, int ty) {

	set<string> results;

	int dx = tx - rx;
	int dy = ty - ry;

	// If robot already at treasure
	if (dx == 0 && dy == 0) {
		results.insert("");
		return results;
	}

	int remH = abs(dx);
	int remV = abs(dy);

	// Determine directions needed
	char hDir = (dx > 0) ? 'E' : 'W';
	char vDir = (dy > 0) ? 'N' : 'S';

	helper(max_distance, remH, remV, hDir, vDir, "", '\0', 0, results);

	return results;
}
