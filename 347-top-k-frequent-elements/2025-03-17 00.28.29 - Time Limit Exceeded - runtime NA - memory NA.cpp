class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> cache;
      for (const auto& num : nums) ++cache[num];

      vector<int> uniqueNums;
      for (const auto& [key, value] : cache) uniqueNums.emplace_back(key);
      int size = uniqueNums.size();

      while (true) {
        int idx = rand() % size;
        swap(uniqueNums[size - 1], uniqueNums[idx]); // swap random pivot to last

        int swapIdx = 0;
        for (int i = 0; i < size - 1; ++i) {
          if (cache[uniqueNums[i]] <= cache[uniqueNums[size - 1]]) {
            swap(uniqueNums[i], uniqueNums[swapIdx]);
            ++swapIdx;
          } 
        }
        swap(uniqueNums[swapIdx], uniqueNums[size - 1]);

        if (swapIdx == size - k) return vector<int>(uniqueNums.begin() + swapIdx, uniqueNums.end());
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