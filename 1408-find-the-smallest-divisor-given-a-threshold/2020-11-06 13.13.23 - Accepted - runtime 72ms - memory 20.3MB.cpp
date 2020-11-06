class Solution {
    bool util(int divisor,int threshold,const vector<int> &nums) {
        int sum = 0;
        for(int n:nums) {
            sum+= (ceil)(static_cast<double>(n)/static_cast<double>(divisor));
        }
        return sum <=threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxElement = *max_element(nums.begin(),nums.end());
        int minElement = 1;
        int mid; 
        while(minElement < maxElement) {
            mid = minElement + (maxElement-minElement)/2;
            if (util(mid,threshold,nums)) {
                maxElement = mid;
            } else {
                minElement = mid + 1;
            }
        }
        return minElement;
    }
};