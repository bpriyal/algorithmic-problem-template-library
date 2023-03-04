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
    vector<pair<int, int>> position = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void util(int facing, int row, int col, Robot& robot) {
        auto p = make_pair(row, col);

        // clean current cell
        visited.emplace(make_pair(row, col));
        robot.clean();

        for (int dir = facing; dir < facing + 4; ++dir) {
            int nx = position[dir % 4].first + row;
            int ny = position[dir % 4].second + col;
            if (visited.count(make_pair(nx, ny)) <= 0 && robot.move()) {
                util(dir % 4, nx, ny, robot);
            }
            // Changed orientation.
            robot.turnRight();
        }

        // move one step back keeping face same
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();

        visited.erase(p);
    }
public:
    void cleanRoom(Robot& robot) {
        util(0, 0, 0, robot);
    }
};