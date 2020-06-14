class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        /*unordered_map<int,int> cache;
        vector<vector<int>> vec(arr.size());
        for(int i = 0;i<arr.size();++i) {
            ++cache[arr[i]];
            vec[i].resize(2,0);
        }
        int i = 0;
        for (auto it = cache.begin();it!=cache.end();++it) {
            vec[i][0] = it->first;
            vec[i][1] = it->second;
            ++i;
        }
        sort(vec.begin(),vec.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1] < a[1];
        });
        int i = 0;
        while(k <= 0) {
            if (vec[i][1] >= k) {
                
            }
        }
        return vec[0][0];*/
        
        
        unordered_map<int,int> cache;
        vector<int> vec;
        for(int i = 0;i<arr.size();++i) {
            ++cache[arr[i]];
        }
        for (auto it = cache.begin();it!=cache.end();++it) {
            vec.push_back(it->second);
        }
        sort(vec.begin(),vec.end());
        int count = vec.size();
        for (auto &x:vec) {
            if (x > k) {
                break;
            } else {
                --count;
                k = k - x;
            }  
        }
        return count;
    }
};