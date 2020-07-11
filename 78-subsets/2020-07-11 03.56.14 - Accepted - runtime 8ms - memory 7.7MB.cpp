class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int powerset = 2 << size;
        set<vector<int>> cache;
        for(int i = 0;i<powerset;++i) {
            vector<int> temp;
            for(int j = 0;j<size;++j) {
                if (i & (1<<j)) {
                    temp.push_back(nums[j]);
                }
            }
            cache.insert(temp);
        }
        return vector<vector<int>>(cache.begin(),cache.end());
    }
};