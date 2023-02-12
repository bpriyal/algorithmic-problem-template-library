class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 < n2) return findMedianSortedArrays(nums2, nums1); // assume n1 is always small

        int l = 0, h = 2 * n2; // to always make the size odd, gives 2n+1 positions

        while (l <= h) {
            int mid2 = (l + h) / 2;
            int mid1 = n1 + n2 - mid2;

            int l1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
            int l2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
            int r1 = mid1 == 2 * n1 ? INT_MAX : nums1[mid1 / 2];
            int r2 = mid2 == 2 * n2 ? INT_MAX : nums2[mid2 / 2];

            if (l1 > r2) l = mid2 + 1;
            else if (l2 > r1) h = mid2 - 1;
            else return static_cast<double>(max(l1, l2) + min(r1, r2)) / 2;
        }

        return -1;
    }
};