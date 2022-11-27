class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>  pq(piles.begin(), piles.end()); // O(n)

        while (k) {
            int temp = pq.top();
            pq.pop();
            //cout<<ceil(temp/2)<<endl;
            pq.emplace(ceil(static_cast<double>(temp)/2));
            --k;
        }

        int result = 0;
        while (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }

        return result;
    }
};