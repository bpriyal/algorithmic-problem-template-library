class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
      int size = trips.size();
      auto comp = [](const vector<int>& v1, const vector<int>& v2) -> bool {
        return v1[2] > v2[2];
      };
      priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

      sort(trips.begin(), trips.end(), [](const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
      });

      int utilizedCapacity = 0;
      for (int i = 0; i < size; ++i) {
        utilizedCapacity = utilizedCapacity + trips[i][0];
        cout << utilizedCapacity << endl;
        while (utilizedCapacity > capacity) {
          // cout << pq.top()[0] << endl;
          if (pq.empty() || trips[i][1] < pq.top()[2]) return false;
          utilizedCapacity -= pq.top()[0];
          pq.pop();
        }
        pq.emplace(trips[i]);
      }

      return true;
    }
};