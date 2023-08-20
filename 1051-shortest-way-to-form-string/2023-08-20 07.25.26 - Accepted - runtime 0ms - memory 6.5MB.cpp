class Solution {
public:
    int shortestWay(string source, string target) {
        int sizeS = source.size();
        int sizeT = target.size();

        int j = 0, minSubStrs = 0;
        while (j < sizeT) {
            ++minSubStrs;
            bool anyMatchFound = false;
            int i = 0;
            while (i < sizeS && j < sizeT) {
                if (source[i] == target[j]) {
                    ++i;
                    ++j;
                    anyMatchFound = true;
                } else {
                    ++i;
                }
            }
            if (!anyMatchFound) return -1;
        }

        return j == sizeT? minSubStrs : -1;
    }
};