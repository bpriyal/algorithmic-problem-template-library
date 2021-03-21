class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> cache;
        
        while(N != 0) {
            cache.push_back(N%10);
            N /= 10;
        }
        
        sort(cache.begin(),cache.end());
        
        do {
            if (cache[0] != 0) {
                int temp = 1;
                int num = 0;
                for(int n:cache) {
                    num = temp*num + n;
                    temp *= 10;
                }
                
                /*if (num == 1) {
                    return true;
                }*/
                //cout<<num<<endl;
                while(num != 0) {
                    if (num == 1) {
                        return true;
                    }
                    if (num % 2 != 0) {
                        break;
                    }
                    num /= 2;
                }
                /*cout<<num<<endl;
                if (num == 0) {
                    return true;
                }*/
            }
        } while (next_permutation(begin(cache),end(cache)));
        
        return false;
    }
};