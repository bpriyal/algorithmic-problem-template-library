class Solution {
public:
    int maxPower(string s) {
        int size = s.size();
        if (size == 0 || size == 1) {
            return size;
        }
        int result = 1;
        
        int temp = 1;
        for(int i = 1;i < size;++i) {
            if (s[i] == s[i-1]) {
                ++temp;
            } else {
                result = max(result,temp);
                temp = 1;
            }
        }
        result = max(result,temp);
        
        return result;
    }
};