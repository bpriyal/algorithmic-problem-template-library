class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
      int size = heights.size();
      int tallestSoFar = 0;
      vector<int> result;

      for (int i = size - 1; i >= 0; --i) {
        if (tallestSoFar < heights[i]) result.emplace_back(i);
        tallestSoFar = max(tallestSoFar, heights[i]);
      }

      reverse(result.begin(), result.end());
      return result;
    }
};