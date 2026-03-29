#ifndef GREEDY_ROBOT_H
#define GREEDY_ROBOT_H
#include <string>
#include <set>

/*
GreedyRobot: Calculate the number of valid routes a robot can use to reach the 
treasure.

    max_distance: maximum number of moves in one direction before a turn is required
    rx: starting X coordinate of robot
    ry: starting Y coordinate of robot
    tx: X coordinate of treasure
    ty: Y coordinate of treasure
*/
std::set<std::string> GreedyRobot(
    int max_distance, int rx, int ry, int tx, int ty); 

#endif