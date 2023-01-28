class Solution {
    static const int oneEnded = INT_MAX;
public:
    int maxDistToClosest(vector<int>& seats) {
        int size = seats.size();
        vector<int> cache(size);
        if (seats[0] == 0) cache[0] = oneEnded;
        else cache[0] = 0;

        for (int i = 1; i < size; ++i) {
            if (seats[i] == 1) cache[i] = 0;
            else {
                cache[i] = cache[i - 1] == oneEnded? oneEnded : cache[i - 1] + 1;
            }
        }

        for (int i = size - 2; i >= 0; --i) {
            if (seats[i] == 1) continue;
            else {
                cache[i] = min(cache[i], cache[i + 1] + 1);
            }
        }
        
        return *max_element(cache.begin(), cache.end());
    }
};