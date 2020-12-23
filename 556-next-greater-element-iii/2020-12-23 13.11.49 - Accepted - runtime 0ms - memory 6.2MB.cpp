class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(str.begin(),str.end());
        long long result = stoll(str);
        return result > INT_MAX || result <= n ? -1:result;
    }
};