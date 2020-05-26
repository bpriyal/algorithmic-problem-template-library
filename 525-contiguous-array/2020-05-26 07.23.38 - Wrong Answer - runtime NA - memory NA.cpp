class Solution {
public:
    
    long int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        vector<int> sumleft(size);
        sumleft[0] = nums[0] == 0 ? -1:1;
        int minele = sumleft[0];
        int maxele = sumleft[0];
        for (int i = 1;i<size;++i) {
            sumleft[i] = sumleft[i-1] + ((nums[i] == 0)? -1:1);
            if (sumleft[i] > maxele) maxele = sumleft[i];
            if (sumleft[i]< minele) minele = sumleft[i];
        }
        vector<int> cache(maxele-minele+1,-1);
        int result;
        for(int i =0;i<size;++i) {
            if (sumleft[i] == 0) result = i+1;
            if (cache[sumleft[i]-minele] == -1) {
                cache[sumleft[i]-minele] = i;
            } else {
                if (i - cache[sumleft[i]-minele] > result) {
                    result = i - cache[sumleft[i]-minele];
                }
            }
        }
        return result;
    }
};