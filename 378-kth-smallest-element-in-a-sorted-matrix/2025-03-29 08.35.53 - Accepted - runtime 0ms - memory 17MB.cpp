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

      size = matrix.size();
      int left = matrix[0][0];
      int right = matrix[size - 1][size - 1];

      while (left < right) {
        int mid = left + (right - left) / 2;
        auto [numberLessThanOrEqual, maxLessThan, minMoreThan] = countLeft(matrix, mid);
        if (numberLessThanOrEqual == k) return maxLessThan;
        else if (numberLessThanOrEqual > k) right = maxLessThan;
        else left = minMoreThan;
      }

      return left;
    }
    std::tuple<int, int, int> countLeft(const vector<vector<int>>& matrix, int mid) {
      int count = 0, maxLessThan = matrix[0][0], minMoreThan = matrix[size - 1][size - 1];
      int row = size - 1, col = 0;

      while (row >= 0 && col < size) {
        if (matrix[row][col] > mid) {
          minMoreThan = min(minMoreThan, matrix[row][col]);
          --row;
        } else {
          count += row + 1;
          maxLessThan = max(maxLessThan, matrix[row][col]);
          ++col;
        }
      }
      cout << "mid: " << mid << ", count: " << count << ", maxLessThan: " << maxLessThan << ", minMoreThan: " << minMoreThan << endl;
      return { count, maxLessThan, minMoreThan };
    }

    
};

// Time complexity: O(Min(N, K)) + K(log)