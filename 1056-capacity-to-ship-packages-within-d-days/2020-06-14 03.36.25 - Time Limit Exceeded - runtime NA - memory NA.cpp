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
            cout<<"**"<<D<<","<<i<<endl;
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
            cout<<mid<<endl;
            if (isValid(weights,D,mid)) {
                r = mid-1;
                cout<<"here1"<<r<<endl;
            }
            else { 
                cout<<"here2"<<endl;
                l = mid + 1;
            }
        }
        return l;
    }
};