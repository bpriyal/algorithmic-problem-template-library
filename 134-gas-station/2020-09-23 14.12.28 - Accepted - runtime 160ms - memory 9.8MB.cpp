class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        for(int i = 0;i<size;++i) {
            int start = i;
            int gasLeft = 0;
            int j;
            for(j = 0;j<size;++j) {
                if (gasLeft < 0) {
                    break;
                }
                gasLeft += gas[(i+j)%size]-cost[(i+j)%size];
            }
            if (j == size && gasLeft >= 0) {
                return i;
            }
        }
        return -1;
    }
};