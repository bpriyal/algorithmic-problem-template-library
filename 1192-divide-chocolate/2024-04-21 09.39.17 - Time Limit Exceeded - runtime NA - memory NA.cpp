class Solution {
    bool isWorkable(const vector<int>& sweetness, int workableVal, int k) {
        int runSweetness = 0;
        int chunks = 0;
        for (int val : sweetness) {
            runSweetness += val;
            if (runSweetness >= workableVal) {
                ++chunks;
                runSweetness = 0;
            }
            if (chunks == k + 1) return true;
        }
        return false;
    }
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int size = sweetness.size();
        int totalSweetness = std::accumulate(sweetness.begin(), sweetness.end(), 0);
        int maxWorkableVal = totalSweetness + 1;
        // cout<<maxWorkableVal<<endl;

        while (maxWorkableVal > 0) {
            if (isWorkable(sweetness, maxWorkableVal, k)) return maxWorkableVal;
            --maxWorkableVal;
        }
        return 0;
    }
};