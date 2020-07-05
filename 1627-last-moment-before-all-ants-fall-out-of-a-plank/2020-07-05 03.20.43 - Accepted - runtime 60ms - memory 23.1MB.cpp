class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftsize = left.size();
        int rightsize = right.size();
        int left_max = 0;
        int right_max = 0;
        if (leftsize != 0) {
            left_max = *max_element(left.begin(),left.end());
        }
        if (rightsize != 0) {
            right_max = n - *min_element(right.begin(),right.end());
        }
        return max(left_max,right_max);
    }
};