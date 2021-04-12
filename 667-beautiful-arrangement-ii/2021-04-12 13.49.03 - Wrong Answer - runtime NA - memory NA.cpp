class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int i = 1,j = n,counter = 0;
        vector<int> result;
        
        while(i <= j) {
            if (k > 1) {
                if (counter % 2 == 0) {
                    result.push_back(i++);
                } else {
                    result.push_back(j--);
                }
                --k;
            } else {
                result.push_back(i++);
            }
            ++counter;
        }
        
        return result;
    }
};