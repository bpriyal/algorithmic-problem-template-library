class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int result = INT_MIN;
        for(int i = 1;i <= size;++i) {
            //cout<<i<<endl;
            int prod = 1;
            vector<int> cache;
            int zeroFound = false;
            for(int j = 0;j < i;++j) {
                if (nums[j] == 0) {
                    zeroFound = true;
                    prod = 0;
                    result = max(result,prod);
                    cache.clear();
                    continue;
                }
                prod *= nums[j];
                if (zeroFound) {
                    cache.push_back(nums[j]);
                }
            }
            result = max(result,prod);
            
            zeroFound = false;
            for(int k = i;k<size;++k) {
                if (nums[k] == 0) {
                    zeroFound = true;
                    prod = 0;
                    result = max(result,prod);
                    cache.clear();
                    continue;
                }
                if (nums[k-i] == 0) {
                    prod = accumulate(cache.begin(),cache.end(),1,multiplies<int>());
                    prod *= nums[k];
                    //cout<<"zeo:"<<prod<<endl;
                    result = max(result,prod);
                    cache.clear();
                    continue;
                }
                
                prod = (prod/nums[k-i])*nums[k];
                
                if (zeroFound) {
                    cache.push_back(nums[k]);
                }
                
                result = max(result,prod);
            }
            
        }
        return result;
    }
};