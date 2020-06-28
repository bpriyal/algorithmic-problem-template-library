class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        /*vector<int> cache(k);
        for(auto &x:arr){
            ++cache[(x%k+k)%k];
        }
        for(auto &x:arr) {
            --cache[(k-((x%k+k)%k))%k];
            if (cache[(k-((x%k+k)%k))%k] < 0) return false;          
        }
        return true; 
        */
        
        vector<int> cache(k);
        for(auto &x:arr){
            ++cache[(x%k+k)%k];
        }
        for(int i = 1;i<k;++i) {
            if (cache[i] != cache[k-i]) return false;
        }
        return cache[0]%2 == 0;
        
    }
};