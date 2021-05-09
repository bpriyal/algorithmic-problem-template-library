class Solution {
public:
    bool isPossible(vector<int>& target) {
        int size = target.size();
        while(true) {
            int max = INT_MIN,maxIndex;
            int sum = 0;
            for(int i = 0;i < size;++i) {
                if (max < target[i]) {
                    max = target[i];
                    maxIndex = i;
                }
                sum += target[i];
            }
            //cout<<max<<endl;
            if (max == 1) {
                return true;
            }
            int temp = max - (sum-max);
            if (temp < 1) {
                return false;
            }
            target[maxIndex] = temp;
        }
        
        return true;
    }
};