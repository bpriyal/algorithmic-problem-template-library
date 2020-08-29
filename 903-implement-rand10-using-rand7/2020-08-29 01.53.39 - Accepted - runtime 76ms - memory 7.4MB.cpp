// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int range1_5;
        do {
            range1_5 = rand7();
        } while (range1_5 > 5);
        
        int range1_6;
        do {
            range1_6 = rand7();
        } while(range1_6 == 7);
        
        if (range1_6 <= 3) {
            return range1_5;
        } else {
            return range1_5 + 5;
        }
    }
};