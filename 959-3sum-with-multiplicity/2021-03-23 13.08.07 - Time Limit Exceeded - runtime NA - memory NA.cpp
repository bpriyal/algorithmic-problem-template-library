class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int size = arr.size();
        unordered_map<int,vector<int>> cache;
        
        int result = 0;
        int mod = pow(10,9)+7;
        
        for(int i=0;i < size;++i) {
           cache[arr[i]].push_back(i);
        }
        
        for(int i = 0;i < size-2;++i) {
            for(int j = i+1;j < size-1;++j) {
                for(int k:cache[target-arr[i]-arr[j]]) {
                    if (k > j) {
                        ++result;
                    }
                }
                result = result % mod;
            }
        }
        return result;
    }
};