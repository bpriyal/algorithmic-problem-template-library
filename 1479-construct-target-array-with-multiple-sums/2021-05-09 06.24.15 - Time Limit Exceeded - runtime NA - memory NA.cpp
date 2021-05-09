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
            int newVal = max - sum;
            if (newVal < 1) {
                return false;
            }
            
            pq.push(newVal);
            sum += newVal;
        }
        
        return true;
    }
};