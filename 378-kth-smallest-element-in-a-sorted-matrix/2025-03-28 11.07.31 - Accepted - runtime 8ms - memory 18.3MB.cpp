class Solution {
    using Tuple = tuple<int, int, int>;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int size = matrix.size();
      priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;

      for (int i = 0; i < min(size, k); ++i) pq.emplace(make_tuple(matrix[i][0], i, 0));

      Tuple result;
      while (k > 0) {
        result = pq.top(); pq.pop();
        int row = get<1>(result);
        int col = get<2>(result);
        if (col != size - 1) pq.emplace(make_tuple(matrix[row][col + 1], row, col + 1));
        --k;
      }

      return get<0>(result);
    }
};