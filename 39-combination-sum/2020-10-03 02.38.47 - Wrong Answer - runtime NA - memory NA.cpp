class Solution {
    set<vector<int>> cache;
    void util(vector<int> &candidates,int target,int currSum,vector<int> &curr) {
        if (currSum > target) {
            return;
        }
        if (currSum == target) {
            for(int x:curr) {
                //printf("%d,",x);
            }
            //cout<<endl;
            sort(curr.begin(),curr.end());
            cache.insert(curr);
            return;
        }
        for(int x:candidates) {
            curr.push_back(x);
           // printf("********:%d||%d\n",currSum,x);
            int sum = 0;
            for(int x:curr) {
                sum += x;
            }
            //cout<<endl;
            util(candidates,target,sum,curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        util(candidates,target,0,curr);
        
        vector<vector<int>> result;
        for(auto x:cache) {
            result.push_back(x);
        }
        return result;
    }
};