class Solution {
    int size;
    int util(const vector<int>& heights, int bricks, int ladders,int run) {
        if (run >= size-1) {
            return run;
        }
        
        int result = INT_MIN;
        if (heights[run+1] <= heights[run]) {
            result = util(heights,bricks,ladders,run+1);
        } else {
            // use bricks
            int usingBricks = INT_MIN;
            if (bricks > heights[run+1]-heights[run]) {
                usingBricks = util(heights,bricks-(heights[run+1]-heights[run]),ladders,run+1);
            }
            
            //use ladders
            int usingLadders = INT_MIN;
            if (ladders > 0) {
                usingLadders = util(heights,bricks,ladders-1,run+1);
            }
            
            result = max(usingBricks,usingLadders);
        }
        
        return result == INT_MIN? run:result;
    }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        size = heights.size();
        
        priority_queue<int> q;
        
        for(int i = 0;i < size-1;++i) {
            if (heights[i] < heights[i+1]) {
                q.push(-(heights[i+1]-heights[i]));
                if (q.size() > ladders) {
                    int temp = (-1)*q.top();
                    q.pop();
                    if (temp > bricks) {
                        return i;
                    } else {
                        bricks -= temp;
                    }
                }
            }
        }
        
        return size-1;
    }
};