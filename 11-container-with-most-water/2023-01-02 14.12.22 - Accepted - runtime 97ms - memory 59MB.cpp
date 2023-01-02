class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int result = 0;

        while (left < right) {
            result = max(result, min(height[left], height[right]) * (right - left));
            height[left] < height[right] ? ++left : --right;
        }

        return result;
    }
};