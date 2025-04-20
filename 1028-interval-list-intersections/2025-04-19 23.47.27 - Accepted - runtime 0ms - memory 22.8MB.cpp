class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
      int size1 = firstList.size();
      int size2 = secondList.size();

      vector<vector<int>> result;
      int i = 0, j = 0;
      while (i < size1 && j < size2) {
        const auto& int1 = firstList[i];
        const auto& int2 = secondList[j];
        int potentialStart = max(int1[0], int2[0]);
        int potentialEnd = min(int1[1], int2[1]);
        if (potentialEnd >= potentialStart) result.emplace_back(vector<int>{potentialStart, potentialEnd});
        if (int1[1] == potentialEnd) ++i;
        if (int2[1] == potentialEnd) ++j;
      }
      return result;
    }
};
// O(S1 + S2)