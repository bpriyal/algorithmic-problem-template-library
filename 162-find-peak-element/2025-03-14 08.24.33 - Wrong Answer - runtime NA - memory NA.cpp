class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        int l = 0;
        int r = size - 1;

        while (l < r) {
          int mid = l + (r - l) / 2;
          
          bool isRightSmaller = mid + 1 >= size || nums[mid + 1] < nums[mid];
          bool isLeftSmaller = mid - 1 < 0 || nums[mid - 1] < nums[mid];

          if (isRightSmaller && isLeftSmaller) return mid;
          else if (!isRightSmaller) l = mid + 1;
          else if (!isLeftSmaller) r = mid - 1;
          else std::cerr << "Invalid case!" << endl;
        }
        return -1;
    }
};