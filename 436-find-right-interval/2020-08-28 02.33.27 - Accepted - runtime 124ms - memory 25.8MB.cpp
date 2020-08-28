class Solution {
    int binarySearch(const vector<pair<int,int>> &cache,int element) {
        int smallest;
        int l = 0;
        int r = cache.size() -1;
        int mid;
        while(l <= r) {
            mid = l+(r-l)/2;
            if (cache[mid].first >= element) {
                smallest = cache[mid].second;
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
        vector<int> result;
        vector<pair<int,int>> cache;
        for(int i=0;i<size;++i) {
            cache.push_back({intervals[i][0],i});
        }
        sort(cache.begin(),cache.end(),[](pair<int,int> &a,pair<int,int> &b){
            return a.first < b.first;
        });
        for(int i=0;i<size;++i) {
            if (cache[size-1].first < intervals[i][1]) {
                result.push_back(-1);
            } else {
                int r = binarySearch(cache,intervals[i][1]);
                result.push_back(r);
            }  
        }
        return result;
    }
};