/*ass NumArray {
    vector<int> nums;
    int n;
    vector<int> cache;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = sqrt(nums.size());
        cache.resize(ceil(nums.size()/n));
        for(int i = 0;i < nums.size();++i) {
            cache[i/n] += nums[i];
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        cache[index/n] += diff;
    }
    
    int sumRange(int left, int right) {
        int wholeleft = left/n+1;
        int wholeright = right/n-1;
        
        int sum = 0;
        
        for(int i = wholeleft;i <= wholeright;++i) {
            sum += cache[i];
        }
        
        //left sum
        for(int i = left;i < n*wholeleft;++i) {
            sum += nums[i];
        }
        
        //right sum
        
        for(int i = n*wholeright;i <= right;++i) {
            sum += nums[i];
        }
        
        return sum;
    }
};*/

class NumArray {
public:
    
    struct Bucket
    {
        int sum;
        vector<int> val;
    };
    
    int bucketNum;
    int bucketSize;
    vector<Bucket> Bs;

    NumArray(vector<int> &nums) {
        int size = nums.size();
        int bucketNum = (int)sqrt(2*size);
        bucketSize = bucketNum/2;
        while(bucketSize * bucketNum<size) ++bucketSize;
        
        Bs.resize(bucketNum);
        for(int i=0, k=0; i<bucketNum; ++i)
        {
            int temp = 0;
            Bs[i].val.resize(bucketSize);
            for(int j=0; j<bucketSize && k<size; ++j, ++k)
            {
                temp += nums[k];
                Bs[i].val[j] = nums[k];
            }
            Bs[i].sum = temp;
        }
    }

    void update(int i, int val) {
        int x = i / bucketSize;
        int y = i % bucketSize;
        Bs[x].sum += (val - Bs[x].val[y]);
        Bs[x].val[y] = val;
    }

    int sumRange(int i, int j) {
        int x1 = i / bucketSize;
        int y1 = i % bucketSize;
		int x2 = j / bucketSize;
        int y2 = j % bucketSize;
        int sum = 0;

		if(x1==x2)
		{
			for(int a=y1; a<=y2; ++a)
			{
				sum += Bs[x1].val[a];
			}
			return sum;
		}

		for(int a=y1; a<bucketSize; ++a)
		{
			sum += Bs[x1].val[a];
		}
        for(int a=x1+1; a<x2; ++a)
        {
            sum += Bs[a].sum;
        }
        for(int b=0; b<=y2; ++b)
        {
            sum += Bs[x2].val[b];
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