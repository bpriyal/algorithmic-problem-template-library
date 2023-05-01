class Solution {
public:
    string breakPalindrome(string palindrome) {
        int size = palindrome.size();
        if (size == 1) return "";
        int i;

        for (i = 0; i < size; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                break;
            }
        }
        if (i == size) {
            palindrome[size - 1] = 'b';
        }
        return palindrome;
    }
};