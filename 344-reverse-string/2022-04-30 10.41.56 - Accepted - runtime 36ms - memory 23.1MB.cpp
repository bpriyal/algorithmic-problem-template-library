class Solution {
    private:
    void swapPair(char &a, char &b) {
        char c = a;
        a = b;
        b = c;
    }
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        
        for(int i = 0;i < size/2;++i) {
            swap(s[i], s[size-i-1]);
        }
    }
};