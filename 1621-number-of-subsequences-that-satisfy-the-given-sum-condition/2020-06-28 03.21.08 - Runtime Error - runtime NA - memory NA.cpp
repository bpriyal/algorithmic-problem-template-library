class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int size = nums.size();
        int sum = 0;
        sort(nums.begin(),nums.end());
        int i,j;
        for (i = 0;i<size;++i) {
            int min = nums[i];
            if (2*min <= target) {
                for(j = i;j<size;++j) {
                    if (min + nums[j] > target) break;
                }
                //cout<<"trying sum"<<endl;
                //printf("i:%d||j:%d\n",i,j);
                //cout<<static_cast<long long int>(pow(2,j-1-i))%static_cast<int>(pow(10,9)+7)<<","<<sum<<endl;
                sum = (sum + static_cast<long long int>(pow(2,j-1-i))%static_cast<int>(pow(10,9)+7))%static_cast<int>(pow(10,9)+7);
                //cout<<"sum success"<<endl;
            } else {
                cout<<i<<endl;
                break;
            }
        }
        return sum;
    }
};