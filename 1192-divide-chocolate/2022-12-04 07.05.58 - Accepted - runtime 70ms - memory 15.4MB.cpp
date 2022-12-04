class Solution {
    int size;
    bool util(const vector<int>& sweetness, int k, int minValue) {
        int runningSum = 0;
        int i;
        for (i = 0; i < size && k; ++i) {
            runningSum += sweetness[i];
            if (minValue <= runningSum) {
                --k;
                runningSum = 0;
            }
        }
        if (i == size) {
            return false;
        }
        runningSum = 0;
        for (int j = i; j < size; ++j) runningSum += sweetness[j];
        return runningSum >= minValue;
    }
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        size = sweetness.size();
        int people = k + 1;
        int left = *min_element(sweetness.begin(), sweetness.end());
        int right = accumulate(sweetness.begin(), sweetness.end(), 0) / people;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            cout<<mid<<endl;
            if (util(sweetness, k, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};