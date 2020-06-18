class Solution {
    bool isHIndex(const vector<int>& citations,int mid) {
        if (citations[mid] == citations.size()-mid) return true;
        return false;
    }
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if (size == 0) return 0;
        /*int low = 0;
        int high = size-1;
        int mid;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (isHIndex(citations,mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return citations[mid];*/
        
        int i = size - 1;
        while (i >= 0) {
            if (citations[i] <= size-i) return citations[i];
            --i;
        }
        return size-i-1;
    }
};