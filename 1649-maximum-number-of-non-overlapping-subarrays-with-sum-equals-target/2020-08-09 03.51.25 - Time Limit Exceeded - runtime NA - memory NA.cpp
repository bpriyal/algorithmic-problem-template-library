class Solution {
    int util(const vector<int> &sum,int target,int l,int count) {
        int size = sum.size();
        /*if (l >= sum.size()) {
            return count;
        }*/
        for(int i = l;i<size-1;++i) {
            for(int j = i+1;j<size;++j) {
                if (sum[i] == sum[j] - target) {
                    //cout<<i<<","<<j<<"count:"<<count<<endl;
                    return max(util(sum,target,j,count+1),util(sum,target,i+1,count));
                }
            }
        }
        return count;
    }
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> sum(size+1);
        sum[0] = 0;
        for(int i = 0;i<size;++i) {
            sum[i+1] = sum[i] + nums[i];  
        }
        return util(sum,target,0,0);
    }
};