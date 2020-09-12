class Solution {
    int prodd(vector<int> &cache) {
        int result=1;
        for(auto x:cache) {
            result *= x;
        }
        return result;
    }
public:
    int maxProduct(vector<int>& nums) {
        /*int size = nums.size();
        int result = INT_MIN;
        for(int i = 1;i <= size;++i) {
            cout<<"i:"<<i<<endl;
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
            
            //zeroFound = false;
            for(int k = i;k<size;++k) {
                if (nums[k] == 0) {
                    zeroFound = true;
                    prod = 0;
                    result = max(result,prod);
                   
                    continue;
                }
                if (nums[k-i] == 0) {
                    prod = prodd(cache);
                    prod *= nums[k];
                    cout<<"zeo:"<<prod<<endl;
                    result = max(result,prod);
                    cache.clear();
                    zeroFound = false;
                    continue;
                }
                
                prod = (prod/nums[k-i])*nums[k];
                
                if (zeroFound) {
                    cache.push_back(nums[k]);
                }
                cout<<prod<<endl;
                result = max(result,prod);
            }
            
        }
        return result;*/
        int fn = 0;
        if(nums.size()==0)
            return 0;
        int max = nums[0], cur = nums[0];
        if(max<0)
            fn = max;
        for(int i=1;i<nums.size();i++) {
            if(cur<0 && fn==0)
                fn = cur;
            if(cur==0) {
                fn = 0;
                cur=nums[i];
            }
            else
            {
                cur = cur * nums[i];
                if(cur<0)
                {
                    if(fn!=0)
                    {
                        int temp = cur/fn;
                        if(temp>max)
                            max = temp;
                    }

                }

            }

            if(cur>max)
                max = cur;    
        }
    
    return max;

    }
};