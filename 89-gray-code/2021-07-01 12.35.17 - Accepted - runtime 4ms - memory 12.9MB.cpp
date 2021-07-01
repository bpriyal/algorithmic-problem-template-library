class Solution {
    void util(bitset<32> &bs,vector<int> &result,int n) {
        if (n == 0) {
            result.push_back(bs.to_ulong());
        } else {
            util(bs,result,n-1);
            bs.flip(n-1);
            util(bs,result,n-1);
        }
    }
public:
    vector<int> grayCode(int n) {
        bitset<32> bs;
        vector<int> result;
        util(bs,result,n);
        
        return result;
    }
};