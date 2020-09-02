class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      set <int> s;
      int n = nums.size();
      for(int i = 0; i< n; i++){
         multiset<int>::iterator it = s.lower_bound(nums[i]);
         if(it != s.end() && *it <= nums[i] + t ) {
             return true;
         }
         if(it != s.begin()){
             it = std::next(it, -1);
             if(*it + t >= nums[i]) {
                 return true;
             }
         }
          
         s.insert(nums[i]);
          
         if(i >= k){
            s.erase(nums[i - k]);
         }
      }
      return false;
  }    
};