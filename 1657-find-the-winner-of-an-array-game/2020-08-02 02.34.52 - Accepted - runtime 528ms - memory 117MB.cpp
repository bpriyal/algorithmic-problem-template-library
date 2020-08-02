class Solution {
    int findLargest(const vector<int> &arr) {
        int max = INT_MIN;
        for(int i=0;i<arr.size();++i) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
public:
    int getWinner(vector<int>& arr, int k) {
        int size = arr.size();
        if (k > size) {
            return findLargest(arr);
        }
        unordered_map<int,int> cache;
        list<int> nums(arr.begin(),arr.end());
        list<int>::iterator it;
        while(true) {
            it = nums.begin();
            int a = *it;
            advance(it,1);
            int b = *it;
            if (a > b) {
                ++cache[a];
                if (cache[a] == k) {
                    return a;
                }
                nums.erase(it);
                nums.push_back(b);
            } else {
                ++cache[b];
                if (cache[b] == k) {
                    return b;
                }
                nums.erase(nums.begin());
                nums.push_back(a);
            }
        }
    }
};