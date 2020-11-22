class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> cache;
        vector<string> alphaToMorse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto &word:words) {
            string temp = "";
            for(char c:word) {
                temp += alphaToMorse[c-'a'];
            }
            cache.insert(temp);
        }
        return cache.size();
    }
};