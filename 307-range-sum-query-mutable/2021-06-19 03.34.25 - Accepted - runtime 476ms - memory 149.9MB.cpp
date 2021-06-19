class NumArray {
    vector<int> nums;
    int n;
    vector<int> cache;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = ceil(nums.size()/sqrt(nums.size()));
        cache.resize(n);
        for(int i = 0;i < nums.size();++i) {
            cache[i/n] += nums[i];
        }
        cout<<"here"<<endl;
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        cache[index/n] += diff;
    }
    
    int sumRange(int left, int right) {
        int wholeleft = left/n;
        int wholeright = right/n;
        
        int sum = 0;
        
        if (wholeleft == wholeright) {
            for(int i = left;i <= right;++i) {
                sum += nums[i];
            }
        } else {
            for(int i = left;i <= (wholeleft+1)*n-1;++i) {
                sum += nums[i];
            }
            
            for(int i = wholeleft+1;i <= wholeright-1;++i) {
                sum += cache[i];
            }
            
            for(int i = wholeright*n;i <= right;++i) {
                sum += nums[i];
            }
        }
        
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */