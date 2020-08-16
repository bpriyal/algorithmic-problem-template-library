class Solution {
public:
    int minOperations(int n) {
        vector<int> arr;
        for(int i = 0;i<n;++i) {
            arr.push_back(2*i+1);
        }
        int mid = n/2;
        int sumLeft = 0,sumRight = 0;
        for(int i = 0;i<mid;++i) {
            sumLeft += arr[mid]-arr[i];
        }
        for(int i = mid+1;i<n;++i) {
            sumRight += arr[i]-arr[mid];
        }
        int diff = abs(sumLeft-sumRight);
        if (diff == 0) {
            return sumRight;
        } else {
            if (sumLeft > sumRight) {
                return sumRight+(n-mid-1)+1;
            } else {
                return sumLeft+(mid)+1;
            }
        }
        return 0;
    }
};