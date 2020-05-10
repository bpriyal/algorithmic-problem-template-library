class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int size = target.size();
        vector<string>result;
        int count=0,inc;
        
        for(inc =1;inc<=n;++inc) {
            if (count == size) break;
            if (inc ==target[count]) {
                result.push_back("Push");
                ++count;
            } else {
                result.push_back("Push");
                result.push_back("Pop");
            }
        }
        return result;
    }
};