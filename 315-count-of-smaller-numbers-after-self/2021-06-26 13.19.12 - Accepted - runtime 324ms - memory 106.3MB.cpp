class FenwickTree{
public:
    FenwickTree(int n):nums_(n+1, 0){}
    
    void update(int i, int val){
        while(i < nums_.size()){
            nums_[i] += val;
            i += lowBit(i);
        }
    }
    
    int query(int i){
        int sum = 0;
        while(i > 0){
            sum += nums_[i];
            i -= lowBit(i);
        }
        return sum;
    }
private:
    vector<int> nums_;
    //static inline int lowBit(int x){return x&(-x);}
    static inline int lowBit(int x){return x&-x;};
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> sorted(nums.begin(), nums.end());
        int rank = 0;
        unordered_map<int, int> ranks;
        for(const auto& num: sorted)
            ranks[num] = ++rank;
        vector<int> ans;
        FenwickTree tree(sorted.size());
        for(int i = nums.size() - 1; i >= 0; i--){
            ans.push_back(tree.query(ranks[nums[i]] - 1));
            tree.update(ranks[nums[i]], 1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};