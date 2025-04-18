class SparseVector {
    unordered_map<int, int> sparseVector;
public:
    const unordered_map<int, int>& getSparseVector() { return sparseVector; }
    SparseVector(vector<int> &nums) {
      for (int i = 0; i < nums.size(); ++i) if (nums[i] != 0) sparseVector.try_emplace(i, nums[i]);
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
      int result = 0;
      for (const auto& [index, value] : vec.getSparseVector()) {
        auto it = sparseVector.find(index);
        if (it != sparseVector.end()) result += value * it->second;
      }
      return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);