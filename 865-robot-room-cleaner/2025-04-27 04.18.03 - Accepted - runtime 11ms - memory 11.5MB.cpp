/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
    set<pair<int, int>> visited;
    // go clockwise - up, right, down, left
    static inline vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void goback(Robot& robot) {
      robot.turnRight(); robot.turnRight(); robot.move(); robot.turnRight(); robot.turnRight();
    }
    void backtracking(Robot& robot, int row, int col, int direction) {
      visited.emplace(make_pair(row, col));
      robot.clean();
      for (int i = 0; i < directions.size(); ++i) {
        int newD = (direction + i) % 4;
        int newRow = row + directions[newD].first;
        int newCol = col + directions[newD].second;
        if (!visited.count(make_pair(newRow, newCol)) && robot.move()) {
          backtracking(robot, newRow, newCol, newD);
          goback(robot); // come back to same direction
        }
        robot.turnRight();
      }
    }
public:
    void cleanRoom(Robot& robot) {
      backtracking(robot, 0, 0, 0);
    }
};