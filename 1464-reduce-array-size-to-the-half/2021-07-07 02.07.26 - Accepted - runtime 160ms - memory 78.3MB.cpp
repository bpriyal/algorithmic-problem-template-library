class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> cache;
        
        for(int num:arr) {
            ++cache[num];
        }
        
        vector<int> frequency;
        
        for(auto it=cache.begin();it != cache.end();++it) {
            frequency.push_back(it->second);
        }
        sort(frequency.begin(),frequency.end(),greater<int>());
        
        int size = arr.size();
        int run = 0;
        int result = 0;
        int i = 0;
        while (run < size/2) {
            run += frequency[i];
           // cout<<frequency[i]<<endl;
            ++i;
            ++result;
        }
        
        return result;
    }
};