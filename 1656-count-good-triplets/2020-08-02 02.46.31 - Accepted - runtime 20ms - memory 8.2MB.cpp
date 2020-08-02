class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int size = arr.size();
        int count = 0;
        for(int i = 0;i < size;++i) {
            for(int j = i+1;j < size;++j) {
                if (abs(arr[i]-arr[j]) <= a) {
                    for(int k = j+1;k < size;++k) {
                        if (abs(arr[j]-arr[k]) <= b && abs(arr[i]-arr[k]) <=c) {
                            ++count;
                        }
                    }
                }
            }
        }
        return count;
    }
};