class Solution {
public:
    int numTrees(int n) {
        vector<int> cache(n+1);
        cache[0] = 1;
        cache[1] = 1;
        for(int i = 2;i<=n;++i) {
            int  sum = 0;
            for(int j = 0;j<i;++j) {
                sum += cache[j]*cache[i-j-1];
                cout<<"sum:"<<sum<<endl;
            }
            cache[i] = sum;
        }
        return cache[n];
    }
};