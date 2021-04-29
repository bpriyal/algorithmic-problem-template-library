class Solution {
    int minI;
    int maxI;
    void binary(vector<int>& nums,int target,int l,int r) {
        if (r < l) {
            return;
        }
        
        int mid = l + (r-l)/2;
        
        if (nums[mid] == target) {
            //cout<<"here"<<endl;
            minI = min(minI,mid);
            maxI = max(maxI,mid);
            
            binary(nums,target,l,mid-1);
            binary(nums,target,mid+1,r);
        } else if (nums[mid] < target) {
            binary(nums,target,mid+1,r);
        } else {
            binary(nums,target,l,mid-1);
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0;
        int r = size - 1;
        minI = INT_MAX;
        maxI = INT_MIN;
        
        binary(nums,target,l,r);
        
        if (minI == INT_MAX) {
            minI = maxI = -1;
        }
        
        return vector<int>({minI,maxI});
    }
};