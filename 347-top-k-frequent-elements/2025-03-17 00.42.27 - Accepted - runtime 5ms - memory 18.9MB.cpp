class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      if (nums.size() == k) return nums;
      unordered_map<int, int> cache;
      for (const auto& num : nums) ++cache[num];

      vector<int> uniqueNums;
      for (const auto& [key, value] : cache) uniqueNums.emplace_back(key);
      int size = uniqueNums.size();
      cout << "size: " << size << endl;

      while (true) {
        auto copyUniqueNums = uniqueNums;
        int idx = rand() % size;
        cout << "random idx: " << idx << endl;
        swap(copyUniqueNums[size - 1], copyUniqueNums[idx]); // swap random pivot to last

        int swapIdx = 0;
        for (int i = 0; i < size - 1; ++i) {
          if (cache[copyUniqueNums[i]] < cache[copyUniqueNums[size - 1]]) {
            swap(copyUniqueNums[i], copyUniqueNums[swapIdx]);
            ++swapIdx;
          } 
        }
        swap(copyUniqueNums[swapIdx], copyUniqueNums[size - 1]);
        cout << "final swapIdx: " << swapIdx << endl;
        if (swapIdx == size - k) return vector<int>(copyUniqueNums.begin() + swapIdx, copyUniqueNums.end());
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