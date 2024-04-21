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
        int l = 0;
        while (size > 1) {
            size /= 2;
            int cmp = reader.compareSub(l, l + size - 1, l + size, l + size + size - 1);
            if (cmp == 0) return l + size + size;
            else if (cmp < 0) l += size;
        }
        return l;
    }
};