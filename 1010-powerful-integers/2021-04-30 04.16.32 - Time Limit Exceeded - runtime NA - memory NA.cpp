class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> result;
        
        for(int i = 0,temp;(temp = pow(x,i)+1) <= bound;++i) {
            for(int j = 0,tempp;(tempp=temp-1+pow(y,j)) <= bound;++j) {
                result.insert(tempp);
            }
        }
        
        return vector<int>(result.begin(),result.end());
    }
};