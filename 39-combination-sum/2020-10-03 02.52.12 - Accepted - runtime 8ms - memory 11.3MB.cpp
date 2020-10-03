class Solution {
    vector<vector<int>> cache;
    void util(vector<int> &candidates,int currSum,vector<int> &curr,int start) {
        if (currSum < 0) {
            return;
        }
        if (currSum == 0) {
            cache.push_back(curr);
            return;
        }
        for(int i = start;i < candidates.size();++i) {
            if (candidates[i] > currSum) {
                break;
            }
            curr.push_back(candidates[i]);
            util(candidates,currSum-candidates[i],curr,i);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        
        sort(candidates.begin(),candidates.end());
        
        util(candidates,target,curr,0);
        
        return cache;
    }
};