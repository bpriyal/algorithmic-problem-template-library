class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int N = quality.size();
        double result = INT_MAX;

        for (int minWageWorker = 0; minWageWorker < N; ++minWageWorker) {
            double factor = static_cast<double>(wage[minWageWorker])/quality[minWageWorker];
            priority_queue<double> prices;
            for (int worker = 0; worker < N; ++worker) {
                double price = factor * quality[worker];
                if (price < wage[worker]) continue;
                if (prices.size() < k) prices.emplace(price);
                else {
                    if (price < prices.top()) {
                        prices.pop();
                        prices.emplace(price);
                    }
                }
            }

            if (prices.size() < k) continue;

            double sum = 0.;
            for (int i = 0; i < k; ++i) {
                sum += prices.top();
                prices.pop();
            }
            result = min(result, sum);
        }

        return result;
    }
};