class Solution {
public:
    vector<int> weight;
    Solution(vector<int>& w) {
        int sum = 0;
        for(int i = 0;i<w.size();++i) {
            sum +=w[i];
            weight.push_back(sum);
        }
    }
    
    int binary_search(int l,int h,int ele) {
        if (ele < weight[l]) return l;
        int mid = l + (h-l)/2;
        if (weight[mid] == ele) return mid+1;
        if (ele > weight[mid]) return binary_search(mid+1,h,ele);
        else {
            if (ele >= weight[mid-1]) return mid;
            else {
                return binary_search(l,mid-1,ele);
            }
        }
        
    }
    
    int pickIndex() {
        return binary_search(0,weight.size()-1,rand() % weight[weight.size()-1]);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */