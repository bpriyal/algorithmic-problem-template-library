class Solution {
    public int trap(int[] height) {
        if (height.length < 3) {
            return 0;
        }
        int water = 0;
        int i = 0;
        if(height[0] < height[1]) {
            i = 1;
        }
        for (; i < height.length - 1 ; ++i) {     
            for (int j = i+2; j < height.length; ++j) {
                if (height[j] >= height[i]){             
                    water += process(i, j, height);
                    i = j - 1;
                    break;
                }
            }
        }
        return water;
    }

    int process(int start, int end, int[] height) {
        int water = 0;
        int h = Math.min(height[end], height[start]);
        for (int i = start + 1; i < end; ++i) {
            water += h - height[i];
        }            
        return water;
    }
}