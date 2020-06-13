class Solution {
public:
    vector<int> util(const vector<int> &nums,int mult,int i,const vector<int> &curr) {
        cout<<"**"<<mult<<" "<<i<<endl;
        if (i>=nums.size()) return curr;
        if (mult%nums[i] ==0 || nums[i]%mult == 0) {
            for(int i=0;i<curr.size();++i) {
                cout<<curr[i]<<" ";
            }
            cout<<endl;
            vector<int> vec1(curr);
            vector<int> vec2(curr);
            int multt = mult;
            if(!std::binary_search(vec1.begin(),vec1.end(),nums[i])) {
                vec1.push_back(nums[i]);
                if (multt < nums[i]) multt = nums[i];
            }
            vec1 = util(nums,multt,i+1,vec1);
            
            vec2 = util(nums,mult,i+1,vec2);
            return vec1.size() > vec2.size()? vec1:vec2;
        }
        return util(nums,mult,i+1,curr);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> curr;
        return util(nums,1,0,curr);
    }
};