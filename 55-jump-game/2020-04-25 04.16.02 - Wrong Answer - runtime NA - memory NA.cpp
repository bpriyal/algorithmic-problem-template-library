class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size =nums.size();
        if (size == 0) return false;
        if (size == 1) return true;
        if (nums[0] == 0) return false;
        int i;
        for (i=0;i<size;i++) {
            cout<<"here"<<endl;
            if (nums[i] == 0) break;
        }
        cout<<i<<endl;
        if (i == size-1) return true;
        /*if (i == size-2) {
            if (nums[i] != 0) {
                return true;
            }
        }*/
        for (int j=0;j<i;++j) {
            if (nums[j] > i-j) {
                return true;
            }
        }
        return false;
        
    }
}; 