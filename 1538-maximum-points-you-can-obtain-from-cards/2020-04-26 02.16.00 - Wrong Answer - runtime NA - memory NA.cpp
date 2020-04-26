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
        for(i=0;i<size-k;++i) {
            cout<<i-k+1<<" "<<i<<endl;
            window+=cardPoints[i] - cardPoints[size-k+i];
            result = max(result,window);
        }
        return result;
    }
};