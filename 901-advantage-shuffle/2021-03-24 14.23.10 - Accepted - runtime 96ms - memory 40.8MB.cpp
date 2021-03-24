class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int size = A.size();
        
        /*sort(A.begin(),A.end());
        vector<int> result;
        
        for(int num:B) {
            bool flag = false;
            for(int &a:A) {
                if (a != -1 && a > num) {
                    result.push_back(a);
                    a = -1;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                for(int &a:A) {
                    if (a != -1) {
                        result.push_back(a);
                        a = -1;
                        break;
                    }
                }
            }
        }*/
        
        multiset<int> cache(A.begin(),A.end());
        
        for(int i = 0;i < size;++i) {
            auto it = *cache.rbegin() <= B[i] ? cache.begin() : cache.upper_bound(B[i]);
            A[i] = *it;
            cache.erase(it);
        }
        
        return A;
    }
};