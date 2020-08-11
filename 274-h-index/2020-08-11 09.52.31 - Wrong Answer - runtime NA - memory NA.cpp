class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        sort(citations.begin(),citations.end());
        for(int i = size-1;i>=0;--i) {
            if (citations[i] == (size - i)) {
                return citations[i];
            }
        }
        return 0;
    }
};