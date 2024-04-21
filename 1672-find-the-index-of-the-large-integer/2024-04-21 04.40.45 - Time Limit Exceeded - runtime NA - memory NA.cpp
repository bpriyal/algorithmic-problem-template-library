/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int size = reader.length();
        int l = 0, r = size - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            cout<<mid<<endl;
            int result = reader.compareSub(l, mid, mid + 1, r);
            if (result == 1) r = mid;
            else if (result == -1) l = mid + 1;
            else {
                int leftSubArraySize = mid - l;
                int rightSubArraySize = r - (mid + 1);
                if (leftSubArraySize > rightSubArraySize) l = mid + 1;
                else if (leftSubArraySize < rightSubArraySize) r = mid;
                else cerr << "Not Valid";
            }
        }
        return l;
    }
};