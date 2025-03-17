class SparseVector {
    vector<pair<int, int>> idxValPairs;
public:
    SparseVector(vector<int> &nums) {
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) idxValPairs.emplace_back(i, nums[i]);
      }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
      int result = 0;
      int i = 0, j = 0;
      while (i < idxValPairs.size() && j < vec.idxValPairs.size()) {
        const auto& [idx1, val1] = idxValPairs[i];
        const auto& [idx2, val2] = vec.idxValPairs[j];
        if (idx1 == idx2) {
          result += val1 * val2;
          ++i;
          ++j;
        }
        else if (idx1 < idx2) ++i;
        else ++j;
      }
      return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);