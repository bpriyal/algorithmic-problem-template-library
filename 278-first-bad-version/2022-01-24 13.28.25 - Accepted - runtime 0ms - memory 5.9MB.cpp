// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    int result;
    void util(int l, int h) {
        int mid = l + (h-l)/2;
        
        if (h < l) return;
        
        if (isBadVersion(mid)) {
            result = min(result, mid);
            util(l, mid - 1);
        } else {
            util(mid+1, h);
        }
    }
public:
    int firstBadVersion(int n) {
        result = n;
        util(1, n);
        
        return result;
    }
};