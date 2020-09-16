class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result=0;
        int mask=0;
        for(int i=31;i>=0;i--){
            mask |= (1<<i);
            unordered_set<int> cache;
            for(int num:nums){
                cache.insert(num&mask);
            }
            int temp=result|(1<<i); 
            for(int prefix:cache){ 
                if(cache.count(temp^prefix)){
                    result=temp;
                    break;
                }
            }
        }
        return result;
    }
};
