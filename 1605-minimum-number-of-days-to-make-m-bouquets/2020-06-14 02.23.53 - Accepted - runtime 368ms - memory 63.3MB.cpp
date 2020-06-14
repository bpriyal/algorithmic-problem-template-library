class Solution {
    bool validconfig(const vector<int>& bloomDay, int m,int k,int mid) {
        int count = 0,sequence =0;
        for (auto &x:bloomDay) {
            if (x <= mid) {
                ++sequence;
            } else {
                sequence = 0;
            }
            if (sequence == k) {
                ++count;
                sequence = 0;
            } 
            if (count == m) {
                return true;
            }
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int size = bloomDay.size();
        if (m*k > size) return -1;
        int l = INT_MAX;
        int h = INT_MIN;
        for(auto &x:bloomDay) {
            l = min(l,x);
            h = max(h,x);
        }
        while(l<=h) {
            int mid = l + (h-l)/2;
            if (validconfig(bloomDay,m,k,mid)) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};