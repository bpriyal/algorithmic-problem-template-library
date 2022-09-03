class Solution {
    int size;
    vector<vector<int>> result;
    
    void util(vector<int>& candidates, int target, int i, int sum, vector<int>& current) {
        if (i >= size || sum > target) return;
        if (sum == target) {
            result.push_back(current);
            return;
        }
        
        current.push_back(candidates[i]);
        util(candidates, target, i, sum + candidates[i], current);
        
        current.pop_back();
        
        util(candidates, target, i + 1, sum, current);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        size = candidates.size();
        vector<int> current;
        util(candidates, target, 0, 0, current);
        
        return result;
    }
};