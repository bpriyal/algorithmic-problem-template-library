class Solution {
    int size;
    int getPos(const vector<int>& nums,int start,int k) {
        int _min = INT_MAX;
        int pos = start;
        for(int i = start;i <= size - k;++i) {
            if (_min > nums[i]) {
                _min = nums[i];
                pos = i;
            }
        }
        return pos;
    }
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        size = nums.size();
        int start = 0;
        vector<int> result;
        while(k > 0) {
            int pos = getPos(nums,start,k);
            result.push_back(nums[pos]);
            start = pos + 1;
            --k;
        }
        return result;
    }
};