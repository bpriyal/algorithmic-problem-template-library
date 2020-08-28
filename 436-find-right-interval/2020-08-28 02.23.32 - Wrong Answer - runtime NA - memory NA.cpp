class Solution {
    int binarySearch(const vector<int> &cache,int element) {
        int smallest;
        int l = 0;
        int r = cache.size() -1;
        int mid;
        while(l <= r) {
            mid = l+(r-l)/2;
            if (cache[mid] >= element) {
                smallest = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return smallest;
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<int> cache,result;
        for(int i=0;i<size;++i) {
            cache.push_back(intervals[i][0]);
        }
        sort(cache.begin(),cache.end());
        for(int i=0;i<size;++i) {
            if (cache[size-1] < intervals[i][1]) {
                result.push_back(-1);
            } else {
                int r = binarySearch(cache,intervals[i][1]);
                result.push_back(r);
            }  
        }
        return result;
    }
};