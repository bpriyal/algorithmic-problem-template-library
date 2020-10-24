class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        /* trivial 
        for(int i = 0;i < size - 2;++i) {
            for(int j = i+1;j < size -1;++j) {
                for(int k = j+1;k < size;++k) {
                    if (nums[i] < nums[k] && nums[i] < nums[j] && nums[k] < nums[j]) {
                        return true;
                    }
                }
            }
        }
        return false;*/
        
        stack<int> st;
        int middleElement = INT_MIN;
        for(int i = size - 1;i >= 0;--i) {
            if (nums[i] < middleElement) {
                return true;
            }
            
            while(!st.empty() && nums[i] > st.top()) {
                middleElement = st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        return false;
    }
};