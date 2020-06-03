class Solution {
public:
    int size;
    int util(const vector<vector<int>> &costs,int i,int a,int b) {
        if (i == size) return 0;
        else if (a == 0) {
            return costs[i][1] + util(costs,i+1,a,b-1);
        } else if (b == 0) {
            return costs[i][0] + util(costs,i+1,a-1,b);
        } else {
            return min(costs[i][0] + util(costs,i+1,a-1,b),costs[i][1] + util(costs,i+1,a,b-1));
        }
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        size = costs.size();
        return util(costs,0,size/2,size/2);
    }
};