class Solution {
    vector<vector<int>> result;
    vector<bool> visited;
    int size;
    
    void util(vector<int>& nums, vector<int>& current) {
        if (current.size() == size) result.push_back(current);
        
        for (int i = 0; i < size; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                current.push_back(nums[i]);
                
                util(nums, current);
                
                visited[i] = false;
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        size = nums.size();
        visited.resize(size, false);
        vector<int> current;
        
        util(nums, current);
        
        return result;
    }
};