class Solution {
    int number;
    int util(const vector<vector<int>>& stones, unordered_map<int, int>& rowMap, unordered_map<int, int>& columnMap, int currentStone, int stonesRemoved) {
        if (currentStone == number) return stonesRemoved;
        int result = INT_MIN;
        // remove the stone
        if (rowMap[stones[currentStone][0]] > 1 || columnMap[stones[currentStone][1]] > 1) {
            --rowMap[stones[currentStone][0]];
            --columnMap[stones[currentStone][1]];
            result = max(result, util(stones, rowMap, columnMap, currentStone + 1, stonesRemoved + 1));
            ++rowMap[stones[currentStone][0]];
            ++columnMap[stones[currentStone][1]];
        }
        //choose to not remove
        result = max(result, util(stones, rowMap, columnMap, currentStone + 1, stonesRemoved));
        return result;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        number = stones.size();
        unordered_map<int, int> rowMap;
        unordered_map<int, int> columnMap;
        int stonesRemoved = 0;

        sort(stones.begin(), stones.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b [1];
            return a[0] < b[0];
        });

        for (auto& stone : stones) {
            ++rowMap[stone[0]];
            ++columnMap[stone[1]];
        }

        return util(stones, rowMap, columnMap, 0, 0);
    }
};