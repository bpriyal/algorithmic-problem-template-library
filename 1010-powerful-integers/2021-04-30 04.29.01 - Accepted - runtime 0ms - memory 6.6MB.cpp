class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> result;
        
        for(int i = 0,temp = 0;(temp = pow(x,i)+1) <= bound;++i) {
            //cout<<temp-1<<","<<i<<endl;
            for(int j = 0,tempp = 0;(tempp=temp-1+pow(y,j)) <= bound;++j) {
                result.insert(tempp);
                if (y == 1) {
                    break;
                }
            }
            if (x == 1) {
                break;
            }
        }
        
        return vector<int>(result.begin(),result.end());
    }
};