class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int size = s.size();
        if (k > size) return 0;
        int left = 0, result = 0;
        unordered_map<char, int> cache;

        for (int right = 0; right < size; ++right) {
            ++cache[s[right]];
            while (cache[s[right]] > 1) {
                --cache[s[left]];
                ++left;
            }
            // cout<<left<<", "<<right<<endl;
            if (right - left + 1 == k) {
                ++result;
                --cache[s[left]];
                ++left;
            }
        }
        return result;
    }
};