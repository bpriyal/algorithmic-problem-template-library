class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> result;
        for(auto x:A) {
           if (x%2==0) {
               result.insert(result.begin(),x);
           } else {
               result.push_back(x);
           }
        }
        return result;
    }
};