class Solution {
    set<vector<int>> cache;
    void util(vector<int> &candidates,int target,int currSum,vector<int> &curr) {
        if (currSum > target) {
            return;
        }
        if (currSum == target) {
            sort(curr.begin(),curr.end());
            cache.insert(curr);
            return;
        }
        for(int x:candidates) {
            curr.push_back(x);
            util(candidates,target,currSum+x,curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        util(candidates,target,0,curr);
        
        vector<vector<int>> result;
        for(auto x:cache) {
            result.push_back(x);
        }
        return result;
    }
};