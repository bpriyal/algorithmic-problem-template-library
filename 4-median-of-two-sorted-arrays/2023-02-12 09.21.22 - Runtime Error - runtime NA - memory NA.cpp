class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 < n2) findMedianSortedArrays(nums2, nums1); // assume n1 is always small

        int l = 0, h = 2 * n2; // to always make the size odd, gives 2n+1 positions

        while (l <= h) {
            int mid2 = (l + h) / 2;
            int mid1 = n1 + n2 - mid2;

            int l1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
            int l2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
            int r1 = mid1 == 2 * n1 ? INT_MAX : nums1[mid1 / 2];
            int r2 = mid2 == 2 * n2 ? INT_MAX : nums2[mid2 / 2];

            //cout<<l1<<","<<l2<<","<<r1<<","<<r2<<endl;

            if (l1 > r2) l = mid2 + 1;
            else if (l2 > r1) h = mid2 - 1;
            else return static_cast<double>(max(l1, l2) + min(r1, r2)) / 2;
        }

        return -1;

    //     int N1 = nums1.size();
    // int N2 = nums2.size();
    // if (N1 < N2) return findMedianSortedArrays(nums2, nums1);	// Make sure A2 is the shorter one.
    
    // int lo = 0, hi = N2 * 2;
    // while (lo <= hi) {
    //     int mid2 = (lo + hi) / 2;   // Try Cut 2 
    //     int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly
        
    //     double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];	// Get L1, R1, L2, R2 respectively
    //     double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
    //     double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
    //     double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];
        
    //     if (L1 > R2) lo = mid2 + 1;		// A1's lower half is too big; need to move C1 left (C2 right)
    //     else if (L2 > R1) hi = mid2 - 1;	// A2's lower half too big; need to move C2 left.
    //     else return (max(L1,L2) + min(R1, R2)) / 2;	// Otherwise, that's the right cut.
    // }
    // return -1;

    }
};