class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int size = nums.size();
        deque<int> q;
        
        for(int i = size-1;i >= 0;--i) {
            int curr = nums[i] + q.empty()? 0:nums[q.front()];
            
            while (!q.empty() && curr >= nums[q.back()]) {
                q.pop_back();
            }
            
            q.push_back(i);
            
            while (i+k <= q.front()) {
                q.pop_front();
            }
            
            nums[i] = curr;
        }
        
        /*for(int x:dp) {
            cout<<x<<"\t";
        }*/
        
        return nums[0];
    }
};