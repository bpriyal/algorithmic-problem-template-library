class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int size = timeSeries.size();
        int sum = 0;
        int range = 0;
        for(int time:timeSeries) {
            if (range <= time) {
                sum += duration;
            } else {
                sum += duration - (range - time);
            }
            range = time + duration;
        }
        return sum;
    }
};