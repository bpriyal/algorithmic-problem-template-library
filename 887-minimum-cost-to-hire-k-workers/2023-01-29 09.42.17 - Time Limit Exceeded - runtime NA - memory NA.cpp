class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int N = quality.size();
        double result = INT_MAX;

        for (int minWageWorker = 0; minWageWorker < N; ++minWageWorker) {
            double factor = static_cast<double>(wage[minWageWorker])/quality[minWageWorker];
            int run = 0;
            vector<double> prices;
            for (int worker = 0; worker < N; ++worker) {
                double price = factor * quality[worker];
                if (price < wage[worker]) continue;
                prices.emplace_back(price);
                ++run;
            }

            if (run < k) continue;
            sort(prices.begin(), prices.end());

            double sum = 0.;
            for (int i = 0; i < k; ++i) {
                sum += prices[i];
            }
            result = min(result, sum);
        }

        return result;
    }
};