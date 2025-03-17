class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      if (nums.size() == k) return nums;
      unordered_map<int, int> cache;
      for (const auto& num : nums) ++cache[num];

      vector<int> uniqueNums;
      for (const auto& [key, value] : cache) uniqueNums.emplace_back(key);
      int size = uniqueNums.size();

      int left = 0;
      int right = size - 1;
      while (left <= right) {
        int idx = left + rand() % (right - left + 1);

        swap(uniqueNums[right], uniqueNums[idx]); // swap random pivot to last
        // Partition
        int swapIdx = left;
        for (int i = left; i < right; ++i) {
          if (cache[uniqueNums[i]] < cache[uniqueNums[right]]) {
            swap(uniqueNums[i], uniqueNums[swapIdx]);
            ++swapIdx;
          } 
        }
        // Put pivot in correct place
        swap(uniqueNums[swapIdx], uniqueNums[right]);

        if (swapIdx == size - k) return vector<int>(uniqueNums.begin() + swapIdx, uniqueNums.end());
        else if (swapIdx < size - k) left = swapIdx + 1;
        else right = swapIdx - 1;
      }

      return vector<int>();

    //   auto comp = [&](int p1, int p2) -> bool { return cache[p1] > cache[p2]; };
    //   priority_queue<int, vector<int>, decltype(comp)> pq(comp);

    //   for (const auto& [key, value] : cache) {
    //     if (pq.size() == k) {
    //       if (cache[pq.top()] < value) {
    //         pq.pop();
    //         pq.emplace(key);
    //       }
    //     } else {
    //       pq.emplace(key);
    //     }
    //   }

    //   vector<int> result;
    //   while (!pq.empty()) {
    //     result.emplace_back(pq.top());
    //     pq.pop();
    //   }
    //   return result;
    }
};

// Time: O(Nlogk)
// Space: O(N)