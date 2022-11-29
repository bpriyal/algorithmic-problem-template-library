class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        int result = 0;
        int capacity = 5000;

        for (int i = 0; i < weight.size(); ++i) {
            if (capacity - weight[i] >= 0) {
                ++result;
                capacity -= weight[i];
            } else break;
        }

        return result;
    }
};