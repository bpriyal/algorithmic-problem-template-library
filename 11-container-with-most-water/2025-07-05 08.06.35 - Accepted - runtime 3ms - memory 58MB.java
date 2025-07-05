class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int left = 0;
        int right = n - 1;
        int MAX = Integer.MIN_VALUE;

        while (left < right) {
            if (height[left] < height[right]) {
                MAX = Math.max(height[left]*(right - left), MAX);
                left++;
            }
            else {
                MAX = Math.max(height[right]*(right - left), MAX);
                right--;
            }
        }

        return MAX;
    }
}