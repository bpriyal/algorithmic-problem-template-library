class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
      vector<int> count(121, 0);
      for (const auto& age : ages) ++count[age];
      int result = 0;

      for (int ageA = 0; ageA < 121; ++ageA) {
        for (int ageB = 0; ageB < 121; ++ageB) {
          if (ageB <= 0.5 * ageA + 7) continue;
          if (ageB > ageA) continue;
          if (ageB > 100 && ageA < 100) continue;
          result += ageA == ageB ? count[ageA] * (count[ageA] - 1) : count[ageA] * count[ageB];
        }
      }

      return result;
    }
};