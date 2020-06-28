class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int size = nums.size();
        long long int sum = 0;
        sort(nums.begin(),nums.end());
        int i,j;
        int modulo = pow(10,9) + 7;
        for (i = 0;i<size;++i) {
            int min = nums[i];
            if (2*min <= target) {
                for(j = i;j<size;++j) {
                    if (min + nums[j] > target) break;
                }
                //cout<<"trying sum"<<endl;
                //printf("i:%d||j:%d\n",i,j);
                //cout<<static_cast<long long int>(pow(2,j-1-i))%static_cast<int>(pow(10,9)+7)<<","<<sum<<endl;
                long long int temp = 1;
                for(int k = 0;k<j-1-i;++k) {
                    temp = (temp*2)%modulo;
                }
                sum = (sum + temp)%modulo;
                //cout<<sum<<endl;
                //cout<<"sum success"<<endl;
            } else {
                break;
            }
        }
        return sum;
    }
};