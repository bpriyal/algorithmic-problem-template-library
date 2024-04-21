class Solution {
    int isWorkable(const vector<int>& sweetness, int workableVal, int k) {
        int runSweetness = 0;
        int chunks = 0;
        for (int val : sweetness) {
            runSweetness += val;
            if (runSweetness >= workableVal) {
                ++chunks;
                runSweetness = 0;
            }
        }
        return chunks;
    }
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int size = sweetness.size();
        int totalSweetness = std::accumulate(sweetness.begin(), sweetness.end(), 0);
        int l = 0, r = totalSweetness + 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int chunks = isWorkable(sweetness, mid, k);
            if (chunks >= k + 1) l = mid + 1;
            else if (chunks < k + 1) r = mid - 1;
        }
        return l - 1;
    }
};