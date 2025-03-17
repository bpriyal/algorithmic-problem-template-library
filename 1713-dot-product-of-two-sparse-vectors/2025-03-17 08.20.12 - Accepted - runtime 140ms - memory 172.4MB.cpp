class SparseVector {
    unordered_map<int, int> idxToValMap;
public:
    SparseVector(vector<int> &nums) {
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) idxToValMap.try_emplace(i, nums[i]);
      }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
      int result = 0;
      for (const auto& [idx, val1] : vec.idxToValMap) {
        // cout << idx << ", " << val1 << endl;
        if (auto it = idxToValMap.find(idx); it != idxToValMap.end()) {
          result += val1 * it->second;
        }
      }
      return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);