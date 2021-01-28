class Solution {
public:
    string getSmallestString(int n, int k) {
        string result;
        while (n > 0) {
            //cout<<(n*26-k)<<endl;
            if (n*26-k >= 26) {
                result += 'a';
                --n;
                --k;
            } else {
                int temp = 26-(n*26-k);
                //cout<<temp<<endl;
                result += ('a'+temp-1);
                k -= temp;
                --n;
            }
        }
        return result;
    }
};