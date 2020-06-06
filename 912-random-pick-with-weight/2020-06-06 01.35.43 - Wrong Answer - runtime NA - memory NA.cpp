class Solution {
public:
    vector<int> weight;
    Solution(vector<int>& w) {
        weight = w;
    }
    
    int pickIndex() {
        vector<int> freq;
        for(int i = 0;i<weight.size();++i) {
           for(int j=0;j<weight[i];++j) {
               freq.push_back(i);
           } 
        }
        return rand()%(weight.size());
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */