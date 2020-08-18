class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        queue<int> q;
        vector<int> result;
        if (N == 1) q.push(0);
        for (int i = 1; i < 10; i++) {
            q.push(i);
        }
        --N;
        while (!q.empty() && N>0) {
            int size = q.size();
            while (size) {
                unsigned long long int t = q.front();
                q.pop();
                int x = t % 10;
                if (K == 0) {
                    q.push (t * 10 + x);
                    --size;
                    continue;
                }
                if (x - K >= 0) q.push(t * 10 + (x - K));
                if (x + K <= 9) q.push(t * 10 + (x + K));
                --size;
            }
            --N;
        }
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};