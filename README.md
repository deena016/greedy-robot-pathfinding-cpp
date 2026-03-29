# greedy-robot-pathfinding-cpp
C++ recursive pathfinding program that generates all valid shortest routes for a robot under movement constraints, with automated test suite validation.

This project implements a recursive pathfinding algorithm that generates all valid shortest routes for a robot to reach a target location on a grid. The robot moves in four directions (N, S, E, W) and must follow specific constraints while navigating to the treasure.

## Overview
The robot starts at a given coordinate `(rx, ry)` and must reach `(tx, ty)`.

### Movement Rules:
- The robot can move **North, South, East, or West**
- Each move must bring the robot **closer to the target**
- The robot **cannot move in the same direction more than `max_distance` times consecutively**

## Features
- Generates **all valid shortest paths**
- Uses **recursion with backtracking**
- Prevents duplicate paths using `std::set`
- Supports **interactive user input mode**
- Includes a **full automated test suite**
- Exports results to a file for inspection

## Example Output
```bash
Num routes: 6
Example valid route: NENNE
