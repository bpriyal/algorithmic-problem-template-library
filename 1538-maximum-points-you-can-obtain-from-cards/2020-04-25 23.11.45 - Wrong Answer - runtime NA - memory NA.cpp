class Solution {
public:
    long int maxScore(vector<int>& cardPoints, long int k) {
        long int size = cardPoints.size();
        long int sum =0;
        long int beg =0;
        long int end = size-1;
        while (k > 0) {
            if (cardPoints[beg] > cardPoints[end]) {
                sum+=cardPoints[beg];
                ++beg;
            } else {
                sum+=cardPoints[end];
                --end;
            }
            --k;
        }
        return sum;
    }
};