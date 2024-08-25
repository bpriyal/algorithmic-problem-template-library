struct Comp {
  bool operator()(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first > p2.first) return true;
    if (p1.first == p2.first) return p1.second > p2.second;
    return false;
  }
};

class Solution {
    static constexpr long mod = 1000000007;

    int powMod(long long num, int exp, int mod){
        long long res = 1;
        for(long long base = num; exp > 0; exp/=2){
            if(exp % 2 == 1){
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
        }
        return res;
    }
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int size = nums.size();
        vector<int> result(size);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
        for (int i = 0; i < size; ++i) pq.emplace(nums[i], i);\
        unordered_map<int, int> freq;
        while (k--) {
          if (freq.size() == size) break;
          auto [value, index] = pq.top();
          pq.pop();
          value = ((value % mod) * multiplier) % mod;
          pq.emplace(value, index);
          ++freq[index];
        }

        int e = k / size, r = k % size;

        while (!pq.empty()) {
          auto [value, index] = pq.top();
          pq.pop();
          result[index] = (value % mod) * powMod(multiplier, e + ((r >= 0)? 1 : 0), mod);
          --r;
        }
        return result;
    }
};