class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int size = nums.size();
        long long int sum = 0;
        int modulo = 1000000007;
        vector<int> pre;
        pre.push_back(1);
        for(int p = 1;p<size;++p) {
            pre.push_back((pre[p-1]<<1)%modulo);
        }
        sort(nums.begin(),nums.end());
        int i,j;
        for (i = 0;i<size;++i) {
            if (2*nums[i] <= target) {
                for(j = size-1;j>=i;--j) {
                    cout<<j<<endl;
                    if (nums[i] + nums[j] <= target) break;
                    cout<<"here1"<<endl;
                }
                sum = (sum + pre[j-i])%modulo;
            } else {
                break;
            }
        }
        return sum;
    }
};