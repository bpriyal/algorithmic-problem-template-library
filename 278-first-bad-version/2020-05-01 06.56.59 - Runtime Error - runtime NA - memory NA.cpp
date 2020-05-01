// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    int index = INT_MAX;
public:
    void badversion_util(int l, int r) {
        if (l>r) return;
        int mid = (l+r)/2;
        cout<<mid<<" "<<l<<" "<<r<<endl;
        if (isBadVersion(mid)) {
            if (index > mid) {
                cout<<"hrll"<<endl;
                index = mid;
            }
            if (l == r){
             return;
            }
           badversion_util(l,mid);
        } else {
           badversion_util(mid+1,r);
        }
    }
    int firstBadVersion(int n) {
        if (n == 0) {
            return 0;
        } 
        badversion_util(1,n);
        return index;
    }
};