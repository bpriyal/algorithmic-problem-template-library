class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int size = nums.size();
      unordered_map<int, int> numToFreqMap;
      for (int num : nums) ++numToFreqMap[num];

    //   auto comp = [&](int num1, int num2) -> bool {
    //     return numToFreqMap[num1] > numToFreqMap[num2];
    //   };
    //   priority_queue<int, vector<int>, decltype(comp)> pq(comp);

    //   for (const auto& [num, freq] : numToFreqMap) {
    //     if (pq.size() < k) pq.emplace(num);
    //     else {
    //       if (numToFreqMap[pq.top()] < freq) {
    //         pq.pop();
    //         pq.emplace(num);
    //       }
    //     }
    //   }

    //   vector<int> result;
    //   while (!pq.empty()) {
    //     result.emplace_back(pq.top());
    //     pq.pop();
    //   }

    //   return result;
    // }

      vector<int> uniqueNums;
      vector<int> result;
      for (const auto& [num, _] : numToFreqMap) uniqueNums.emplace_back(num);

      int l = 0, r = uniqueNums.size() - 1;

      while (l <= r) {
        for (int num : uniqueNums) cout << num << "\t";
        cout << endl;
        int random = l + (rand() % (r - l + 1));
        swap(uniqueNums[random], uniqueNums[r]);
        int inflection = l;
        cout << "random: " << random << endl;
        for (int i = l; i < r; ++i) {
          if (numToFreqMap[uniqueNums[i]] >= numToFreqMap[uniqueNums[r]]) {
            swap(uniqueNums[i], uniqueNums[inflection]);
            ++inflection;
          }
        }
        swap(uniqueNums[inflection], uniqueNums[r]);
        cout << "inflection: " << inflection << endl;
        if (inflection == k - 1) return vector<int>(uniqueNums.begin(), uniqueNums.begin() + k);
        else if (inflection < k) l = random + 1;
        else r = random - 1;
      }
      return vector<int>();
    }

};

// O(N) + O(NLogK)