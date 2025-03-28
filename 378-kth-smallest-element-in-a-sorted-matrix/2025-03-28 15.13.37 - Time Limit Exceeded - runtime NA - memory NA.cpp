class Solution {
    using Tuple = tuple<int, int, int>;
    int size;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      // int size = matrix.size();
      // priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;

      // for (int i = 0; i < min(size, k); ++i) pq.emplace(make_tuple(matrix[i][0], i, 0));

      // Tuple result;
      // while (k > 0) {
      //   result = pq.top(); pq.pop();
      //   int row = get<1>(result);
      //   int col = get<2>(result);
      //   if (col != size - 1) pq.emplace(make_tuple(matrix[row][col + 1], row, col + 1));
      //   --k;
      // }

      // return get<0>(result);

      if (k == 1) return matrix[0][0];
      size = matrix.size();
      int left = matrix[0][0];
      int right = matrix[size - 1][size - 1];

      while (left <= right) {
        int mid = left + (right - left) / 2;
        auto [count, maxLessThan, minMoreThan] = countLeft(matrix, mid);
        if (count == k) return maxLessThan;
        else if (count > k) right = maxLessThan;
        else left = minMoreThan;
      }

      return -1;
    }

    std::tuple<int, int, int> countLeft(const vector<vector<int>>& matrix, int mid) {
      int row = size - 1;
      int col = 0;
      int count = 0;
      int maxLessThan = matrix[0][0];
      int minMoreThan = matrix[row][row];

      while (row >= 0 && col < size) {
        const auto& num = matrix[row][col];
        if (num <= mid) {
          count += row + 1;
          maxLessThan = max(maxLessThan, num);
          ++col;
        } else {
          minMoreThan = min(minMoreThan, num);
          --row;
        }
      }
      cout << "mid: " << mid << ", count: " << count << ", maxLessThan: " << maxLessThan << ", minMoreThan: " << minMoreThan << endl;
      return {count, maxLessThan, minMoreThan};
    }
};

// Time complexity: O(Min(N, K)) + K(log)