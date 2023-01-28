class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int size = seats.size();
        int p1 = 0, p2 = 0;
        int result = 0;
        bool firstPointerSet = false;
        int i = 0;

        while (i < size) {
            if (seats[i] == 1) {
                if (firstPointerSet) {
                    p2 = i;
                    result = max(result, (p2 - p1)/2);
                    p1 = p2;
                } else {
                    p1 = i;
                    firstPointerSet = true;
                }
            } 
            ++i;
        }

        return p2? result : max({ result, abs(size - 1 - p1), p1 });
    }
};