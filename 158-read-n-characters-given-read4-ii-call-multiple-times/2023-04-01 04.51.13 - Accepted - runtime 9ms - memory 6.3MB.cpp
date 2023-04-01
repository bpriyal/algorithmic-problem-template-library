/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
    char buf4[4];
    int numberUnusedChars = 0;
    int charsRead = 4;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        cout<<"entering"<<endl;
        int temp = n;
        int number = 0;
        while (temp) {
            int charactersToCopy = INT_MAX;
            if (numberUnusedChars) {
                cout<<"if"<<numberUnusedChars<<endl;
                charactersToCopy = min(temp, numberUnusedChars);
                int i;
                for (i = 0; i < charactersToCopy; ++i) {
                    *(buf + number + i) = *(buf4 + (charsRead - numberUnusedChars) + i);
                }
                *(buf + number + i) = '\0';
                cout<<"buf:"<<buf<<endl;
                numberUnusedChars -= charactersToCopy;
                number += charactersToCopy;
                temp -= charactersToCopy;
            } else {
                buf4[0] = buf4[1] = buf4[2] = buf4[3] = '\0';
                if (charsRead < 4) return number;
                numberUnusedChars = charsRead = read4(buf4);
                if (!numberUnusedChars) return number;
                // charactersToCopy = min(temp, charactersRead);
                // for (int i = 0; i < charactersToCopy; ++i) {
                //     *(buf + number + i) = *(buf4 + i);
                // }
            }
        }
        return number;
    }
};