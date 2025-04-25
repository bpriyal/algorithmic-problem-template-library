class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
      int size = trips.size();
      // auto comp = [](const vector<int>& v1, const vector<int>& v2) -> bool {
      //   return v1[2] > v2[2];
      // };
      // priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

      // sort(trips.begin(), trips.end(), [](const vector<int>& v1, const vector<int>& v2) {
      //   return v1[1] < v2[1];
      // });

      // int utilizedCapacity = 0;
      // for (int i = 0; i < size; ++i) {
      //   utilizedCapacity = utilizedCapacity + trips[i][0];
      //   while (utilizedCapacity > capacity) {
      //     if (pq.empty() || trips[i][1] < pq.top()[2]) return false;
      //     utilizedCapacity -= pq.top()[0];
      //     pq.pop();
      //   }
      //   pq.emplace(trips[i]);
      // }

      // return true;

      vector<int> timestamps(1001, 0);
      for (const auto& trip : trips) {
        timestamps[trip[1]] += trip[0];
        timestamps[trip[2]] -= trip[0];
      }

      int usedCapacity = 0;
      for (int i = 0; i < 1001; ++i) {
        usedCapacity += timestamps[i];
        if (usedCapacity > capacity) return false;
      }
      return true;
    }
};


// O(nlogn)