class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int size = nums.size();
        long curr = 0;
        deque<int> q;
        
        for(int i = size-1;i >= 0;--i) {
            curr = nums[i] + (q.empty()? 0:nums[q.front()]);
            
            while (!q.empty() && curr > nums[q.back()]) {
                q.pop_back();
            }
            
            q.push_back(i);
            
            if (i+k <= q.front()) {
                q.pop_front();
            }
            
            nums[i] = curr;
        }
        
        for(int x:nums) {
            cout<<x<<"\t";
        }
        
        return curr;
    }
};