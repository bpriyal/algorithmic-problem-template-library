class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        sort(citations.begin(),citations.end());
        for(int i = size-1;i>=0;--i) {
            if (i == (size - i - 1)) {
                return i+1;
            }
        }
        return 0;
    }
};