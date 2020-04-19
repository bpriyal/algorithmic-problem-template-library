class Solution {
public:
    int binarySearch(vector<int> arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 
    
    int search(vector<int>& nums, int target) {
        if (nums.size()==0) return -1;
        int index=-1;
        for(auto i=1;i<nums.size()-1;++i) {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                index =i;
                break;
            }
        }
        vector<int> temp;
        for (int j=index+1;j<nums.size();++j) {
            temp.push_back(nums[j]);
        }
        
        for (int j=0;j<=index;++j) {
            temp.push_back(nums[j]);
        }
        
        
        
        int found=binarySearch(temp,0,temp.size()-1,target);
        if(found==-1) return -1;
        return found+index+1;
        
        return 0;
    }
};