class Solution {
    bool isVowel(char x) {
         if (x == 'a' || x == 'e' || x == 'i' ||  
        x == 'o' || x == 'u' || x == 'A' ||  
        x == 'E' || x == 'I' || x == 'O' || x == 'U') {
             return true;
         }
        return false;
    }
public:
    string toGoatLatin(string S) {
        if (S.empty()) {
            return "";
        }
        vector<string> words;
        string word = "";
        for(auto &x:S) {
            if (x == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += x;
            }
        }
        
        string buffer = "a";
        string ma = "ma";
        words.push_back(word);
        string result = "";
        for(auto word:words) {
            if (!isVowel(word[0])) {
                char c = word[0];
                word.erase(0,1);
                word += c;
            }
            word += ma;
            word += buffer;
            buffer += "a";
            result += word;
            result += " ";
        }
        result.pop_back();
        return result;
    }
};