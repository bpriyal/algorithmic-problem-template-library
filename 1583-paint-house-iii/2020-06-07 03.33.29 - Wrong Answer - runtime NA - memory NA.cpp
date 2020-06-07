class Solution {
public:
    vector<int> house_list;
    vector<vector<int>> price;
    vector<int> color;
    
    int util(int houseno,int t,int nc) {
        if (houseno >= house_list.size() || t < 0) {
            return t==0 ? 0:10001;
        }
        int res;
        if (house_list[houseno] == 0) {
            res = INT_MAX;
            for (auto &c:color) {
                res = min(res,price[houseno][c-1]+util(houseno+1,(nc == c)? t:t-1,c));
            }
        } else {
            res = util(houseno+1,(house_list[houseno]==nc)? t:t-1,house_list[houseno]);
        }
        return (houseno == 0 && res==10001)? -1:res;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        house_list = houses;
        price = cost;
        for(int i = 1;i<=n;++i) color.push_back(i);
        return util(0,target,0);
    }
};