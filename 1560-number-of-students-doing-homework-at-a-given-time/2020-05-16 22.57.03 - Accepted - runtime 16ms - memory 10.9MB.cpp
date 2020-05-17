class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int size = startTime.size();
        int i;
        int count = 0;
        for(i = 0;i<size;++i) {
            if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
                ++count;
            }
        }
        return count;
    }
};