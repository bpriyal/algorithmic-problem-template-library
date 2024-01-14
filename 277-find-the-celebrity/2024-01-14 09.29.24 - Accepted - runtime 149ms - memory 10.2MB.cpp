/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
    int _n;
    bool _isCelebrity(int possibleCelebrity_) {
        for (int i = 0; i < _n; ++i) {
            if (possibleCelebrity_ == i) continue;
            if (knows(possibleCelebrity_, i) || !knows(i, possibleCelebrity_)) return false;
        }
        return true;
    }
public:
    int findCelebrity(int n) {
        _n = n;
        int possibleCelebrity = 0;
        for (int j = 1; j < n; ++j) {
            if (knows(possibleCelebrity, j)) possibleCelebrity = j;
        }
        cout<<possibleCelebrity<<endl;
        return _isCelebrity(possibleCelebrity)? possibleCelebrity : -1;
    }
};
