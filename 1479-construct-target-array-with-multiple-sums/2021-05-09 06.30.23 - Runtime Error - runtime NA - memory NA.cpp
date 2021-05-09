class Solution {
public:
    bool isPossible(vector<int>& target) {
        int size = target.size();
        priority_queue<int> pq;
        int sum = 0;
        for(int i = 0;i < size;++i) {
            pq.push(target[i]);
            sum += target[i];
        }
        
        while (true) {
            int max = pq.top();
            pq.pop();
            sum -= max;
            
            if (max == 1 || sum == 1) {
                return true;
            }
            if (max < sum || sum == 0 || max%sum == 0) {
                return false;
            }
            
            max = max%sum;
            pq.push(max);
            sum += max;
        }
        
        return true;
    }
};