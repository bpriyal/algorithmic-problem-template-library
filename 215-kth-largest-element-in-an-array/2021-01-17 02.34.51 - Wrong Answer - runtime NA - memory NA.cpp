class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        set<int> s;
        for(int num:nums) {
            s.insert(num);
        }
        auto it = s.end();
        while(k > 0) {
           --it;
            --k;
        }
        return *it;
        //return *(s.end()-k);
        //return s[nums.size()-k];
    }
};