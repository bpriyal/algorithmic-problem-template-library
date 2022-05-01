class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        int transitionIndex = INT_MAX;
        
        for (int i = 0;i < size - 1;++i) {
            if (nums[i] < 0 && nums[i+1] >= 0) {
                transitionIndex = i;
                break;
            }
        }
        
        //cout<<transitionIndex;
        int negI, posI;
        
        if (transitionIndex == INT_MAX) {
            if (nums[0] < 0) {
                negI = size - 1;
                posI = size;
            } else {
                negI = -1;
                posI = 0;
            }
        } else {
            negI = transitionIndex;
            posI = negI + 1;
        }
        
        
        vector<int> result;
        
        while (negI >= 0 && posI < size) {
            if (abs(nums[negI]) > nums[posI]) {
                result.push_back(nums[posI]*nums[posI]);
                ++posI;
            } else {
                result.push_back(nums[negI]*nums[negI]);
                --negI;
            }
        }
        
        while (negI >= 0) {
            result.push_back(nums[negI]*nums[negI]);
            --negI;
        }
        
        while (posI < size) {
            result.push_back(nums[posI]*nums[posI]);
            ++posI;
        }
        
        return result;
    }
};