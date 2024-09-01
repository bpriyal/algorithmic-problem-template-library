class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int column1 = coordinate1[0] - 'a' + 1;
        int row1 = coordinate1[1] - '0';

        int column2 = coordinate2[0] - 'a' + 1;
        int row2 = coordinate2[1] - '0';

        return ((column1 + row1) % 2) == ((column2 + row2) % 2);
    }
};