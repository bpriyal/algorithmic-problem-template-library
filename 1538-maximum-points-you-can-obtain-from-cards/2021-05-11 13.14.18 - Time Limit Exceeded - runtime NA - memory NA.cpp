class Solution {
    int _max;
    void util(const vector<int> &cardPoints,int k,int l,int r,int sum) {
        if (k == 0) {
            _max = max(_max,sum);
        }
        
        if (l > r) {
            return;
        }
        
        //pick left element
        util(cardPoints,k-1,l+1,r,sum+cardPoints[l]);
        
        //pick right element
        util(cardPoints,k-1,l,r-1,sum+cardPoints[r]);
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        _max = INT_MIN;
        util(cardPoints,k,0,cardPoints.size()-1,0);
        return _max;
    }
};