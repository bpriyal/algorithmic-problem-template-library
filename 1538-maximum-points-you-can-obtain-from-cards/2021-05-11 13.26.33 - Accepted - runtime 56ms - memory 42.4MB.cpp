class Solution {
    int util(const vector<int> &cardPoints,int k,int l,int r,int sum) {
        if (k == 0) {
            return sum;
        }
        
        if (l > r) {
            return 0;
        }
        
        //pick left element
        int left = util(cardPoints,k-1,l+1,r,sum+cardPoints[l]);
        
        //pick right element
        int right = util(cardPoints,k-1,l,r-1,sum+cardPoints[r]);
        
        return max(left,right);
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int size = cardPoints.size();
        int slidingWindowSize = size-k;
        int slidingSum = 0;
        int result = INT_MIN;
        for(int i = 0;i < size;++i) {
            sum += cardPoints[i];
            
            if (i < slidingWindowSize) {
                slidingSum += cardPoints[i];
            }
        }
        
        result = max(result,sum-slidingSum);
        
        for(int i = slidingWindowSize;i < size;++i) {
            slidingSum += cardPoints[i] - cardPoints[i-slidingWindowSize];
            result = max(result,sum-slidingSum);
        }
        
        return result;
    }
};