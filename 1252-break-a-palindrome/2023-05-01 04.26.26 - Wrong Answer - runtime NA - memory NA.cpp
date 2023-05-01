class Solution {
public:
    string breakPalindrome(string palindrome) {
        int size = palindrome.size();
        int i;

        for (i = 0; i < size; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                break;
            }
        }

        return i == size? "" : palindrome;
    }
};