class Solution {
    struct comp {
        bool operator()(pair<int,int> a,pair<int,int> b) {
            return (a.second > b.second);
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cache;
        for(auto &num:nums) {
            ++cache[num];
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> minheap;
        for(auto &p:cache) {
            minheap.push(p);
            if (minheap.size() > k) minheap.pop();
        }
        
        vector<int> result;
        while(!minheap.empty()) {
            result.push_back(minheap.top().first);
            minheap.pop();
        }
        return result;
    }
};