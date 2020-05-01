// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
   long int index = LONG_MAX;
public:
    void badversion_util(long int l, long int r) {
        if (l == r) {
          if (index > l) {
              index = l;
          }
          return;
        }
        if (l>r) return;
        int mid = (l+r)/2;
        cout<<mid<<" "<<l<<" "<<r<<endl;
        if (isBadVersion(mid)) {
            if (index > mid) {
                cout<<"hrll"<<endl;
                index = mid;
            }
           badversion_util(l,mid);
        } else {
           badversion_util(mid+1,r);
        }
    }
    long int firstBadVersion(long int n) {
        if (n == 0) {
            return 0;
        } 
        badversion_util(1,n);
        return index;
    }
};