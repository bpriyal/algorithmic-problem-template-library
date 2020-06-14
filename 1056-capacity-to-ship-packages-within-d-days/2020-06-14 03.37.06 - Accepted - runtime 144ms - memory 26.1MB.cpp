class Solution {
    bool isValid(const vector<int> &weights,int D, int mid) {
        int run = 0;
        for (int i = 0;i<weights.size();++i) {
            if (D != 0 && mid >= run + weights[i]) {
                run = run + weights[i];
            } else {
                --D;
                if (D == 0 && i == weights.size() - 1) return false;
                if (weights[i] > mid) return false;
                run = weights[i];
            }
            if (D == 0 && i != weights.size() - 1) return false;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = INT_MAX;
        int r = 0;
        for (auto &x:weights) {
            l = min(l,x);
            r = max(r,x);
        }
        r = r*weights.size()+1;
        int mid;
        while (l<=r) {
            mid = l+(r-l)/2;
            if (isValid(weights,D,mid)) {
                r = mid-1;
            }
            else { 
                l = mid + 1;
            }
        }
        return l;
    }
};