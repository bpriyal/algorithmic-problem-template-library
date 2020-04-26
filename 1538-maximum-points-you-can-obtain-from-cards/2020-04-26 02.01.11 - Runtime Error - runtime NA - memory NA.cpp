class Solution {
public:
    long int max(long int a, long int b) {
        return (a > b)? a:b;
    }
    
    long int maxScore(vector<int>& cardPoints, long int k) {
        long int window =0 ;
        long int size = cardPoints.size();
        int i;
        for (i = size-k;i<size;++i) {
            window+=cardPoints[i];
        }
        cout<<window<<endl;
        long int result = window;
        for(i=size-k;i<size;i++) {
            window+=cardPoints[i-k+1] - cardPoints[i];
            result = max(result,window);
        }
        return result;
    }
};