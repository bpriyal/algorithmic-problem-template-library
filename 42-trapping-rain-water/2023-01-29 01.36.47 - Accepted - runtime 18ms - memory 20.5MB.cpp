class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int trappedWater = 0;

        if (!size) return 0;

        vector<int> left_max(size);
        vector<int> right_max(size);

        left_max[0] = height[0];
        right_max[size - 1] = height[size - 1];

        for (int i = 1; i < size; ++i) left_max[i] = max(left_max[i - 1], height[i]);
        for (int i = size - 2; i >= 0; --i) right_max[i] = max(right_max[i + 1], height[i]);

        for (int i = 0; i < size; ++i) {
            trappedWater += min(left_max[i], right_max[i]) - height[i];
        }

        return trappedWater;
    }
};