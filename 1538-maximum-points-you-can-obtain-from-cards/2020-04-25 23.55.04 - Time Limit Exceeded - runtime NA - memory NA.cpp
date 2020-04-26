class Solution {
public:
    long int max(long int a, long int b) {
        return (a > b)? a:b;
    }
    long int util(const vector<int> cardPoints,long int beg, long int end,long int k) {
        cout<<beg<<" "<<end<<" "<<k<<endl;
        if (k ==0){
            cout<<"returning"<<endl;
            return 0;
        }
        long int start = beg+1;
        long int finish = end -1;
        return max(cardPoints[beg]+util(cardPoints,start,end,k-1),cardPoints[end]+util(cardPoints,beg,finish,k-1));
    }
    
    long int maxScore(vector<int>& cardPoints, long int k) {
        long int size = cardPoints.size();
        long int sum =0;
        long int beg =0;
        long int end = size-1;
        long int k2=k;
        cout<<"k2"<<k2<<endl;
        long int sum1 = cardPoints[beg]+util(cardPoints,beg+1,end,--k);
        cout<<"between"<<endl;
        long int sum2 = cardPoints[end]+util(cardPoints,beg,end-1,--k2);
        return max(sum1,sum2);
    }
};