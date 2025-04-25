class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
      vector<double> medians;
      multiset<int> lo, hi;

      for (int i = 0; i < nums.size(); ++i) {
        if (i >= k) {
          if (nums[i - k] <= *lo.rbegin()) lo.erase(lo.find(nums[i - k])); // num in lo multiset
          else hi.erase(hi.find(nums[i - k])); // num in hi multiset
        }

        // insert into lo first such that there is a sorting
        lo.emplace(nums[i]);
        // move largest number to hi and remove from lo
        hi.emplace(*lo.rbegin()); lo.erase(std::prev(lo.end()));

        // rebalance the sets
        if (lo.size() < hi.size()) {
          lo.emplace(*hi.begin());
          hi.erase(hi.begin());
        }

        if (i >= k - 1) {
          medians.emplace_back(k & 1 ? *lo.rbegin() : (static_cast<double>(*lo.rbegin()) + *hi.begin()) / 2);
        }
      }

      return medians;
    }
};