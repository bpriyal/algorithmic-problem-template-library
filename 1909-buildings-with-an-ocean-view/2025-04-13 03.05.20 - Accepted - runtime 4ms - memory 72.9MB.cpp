class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
      int size = heights.size();
      int maxHeightSoFar = -1;
      vector<int> result;

      for (int i = size - 1; i >= 0; --i) {
        if (heights[i] > maxHeightSoFar) result.emplace_back(i);
        maxHeightSoFar = max(maxHeightSoFar, heights[i]);
      }

      reverse(result.begin(), result.end());
      return result;
    }
};