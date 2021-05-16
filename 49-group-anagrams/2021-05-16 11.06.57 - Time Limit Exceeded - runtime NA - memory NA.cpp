class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int numberStrings = strs.size();
        
        vector<vector<int>> cache(numberStrings,vector<int>(26,0));
        vector<bool> used(numberStrings,false);
        vector<vector<string>> result;
        
        for(int i = 0;i < numberStrings;++i) {
            for(char c:strs[i]) {
                ++cache[i][c-'a'];
            }
        }
        
        for(int i = 0;i < numberStrings;++i) {
            vector<string> temp;
            if (used[i]) {
                continue;
            }
            used[i] = true;
            temp.push_back(strs[i]);
            for(int j = i+1;j < numberStrings;++j) {
                if (used[j]) {
                    continue;
                }
                
                if (cache[i] == cache[j]) {
                    temp.push_back(strs[j]);
                    used[j] = true;   
                } 
            }
            result.push_back(temp);
        }
        
        return result;
    }
};