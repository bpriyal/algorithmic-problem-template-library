class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> cache;
        for(int i =0;i<arr.size();++i) {
            int a = arr[i]%k;
            a = a >0 ? a:a+k;
            ++cache[a%k];
        }
        for(int i =0;i<arr.size();++i) {
            int a = arr[i]%k;
            a = a >0 ? a:a+k;
            if (cache[(k-a)%k] <= 0) {
                return false;
            }
            --cache[(k-a)%k];
        }
        return true;
    }
};