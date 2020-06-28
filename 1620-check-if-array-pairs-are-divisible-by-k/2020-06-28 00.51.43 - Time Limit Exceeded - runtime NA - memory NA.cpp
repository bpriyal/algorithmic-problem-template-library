class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cache(k);
        for(auto &x:arr){
            cout<<(x%k+k)%k<<endl;
            ++cache[(x%k+k)%k];
        }
        for(auto &x:arr) {
            cout<<k-((x%k+k)%k)<<endl;
            --cache[(k-((x%k+k)%k))%k];
            if (cache[(k-((x%k+k)%k))%k] < 0) return false;          
        }
        return true;
    }
};