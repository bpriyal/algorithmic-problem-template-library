class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int size = words.size();
        unordered_map<string, int> cache;
        
        int result = 0, unpaired = 0;
        
        for(auto& word : words) {
            
            if (word[0] == word[1]) {
                if (cache[word] > 0) {
                    --cache[word];
                    --unpaired;
                    result += 4;
                } else {
                    ++cache[word];
                    ++unpaired;
                }
            } else {
                string reverse = {word[1], word[0]};
                
                if (cache[reverse] > 0) {
                    result += 4;
                    --cache[reverse];
                }
                else ++cache[word];
            }
        }
        
        result += unpaired * 2;
        
        return result;
    }
};