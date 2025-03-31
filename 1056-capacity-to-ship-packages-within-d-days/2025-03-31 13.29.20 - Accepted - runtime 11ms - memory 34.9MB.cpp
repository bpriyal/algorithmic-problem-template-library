class Solution {
    bool checkPossibility(const vector<int>& weights, int weight, int days) {
      int run = 0;
      int expectedDays = 1;
      for (int i = 0; i < weights.size(); ++i) {
        run += weights[i];
        if (weight < run) {
          run = weights[i];
          ++expectedDays;
        }
      }
      return expectedDays <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
      int sum = 0;
      int maxWeight = INT_MIN;
      for (int weight : weights) {
        sum += weight;
        maxWeight = max(maxWeight, weight);
      }
      int left = maxWeight;
      int right = sum;

      while (left < right) {
        int mid = left + (right - left) / 2;
        auto possible = checkPossibility(weights, mid, days);
        if (!possible) left = mid + 1;
        else right = mid;
      }
      return left;
    }
};