class WordDictionary {
    WordDictionary *dict[26];
    bool isEndOfWord;
    bool search(string word,WordDictionary *root) {
        for(int i = 0;i<word.size();++i) {
            if (word[i] == '.') {
                for(int j = 0;j<26;++j) {
                    if (root->dict[j] != nullptr) {
                        if (search(word.substr(i+1),root->dict[j])) {
                            return true;
                        }
                    }
                }
                return false;
            }
            if (root->dict[word[i]-'a'] == nullptr) {
                return false;
            }
            root = root->dict[word[i]-'a'];
        }
        return root->isEndOfWord;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        for(int i=0;i<26;++i) {
            dict[i] = nullptr;
        }
        isEndOfWord = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *root = this;
        for(char c:word) {
            if (root->dict[c-'a'] == nullptr) {
                root->dict[c-'a'] = new WordDictionary();                
            }
            root = root->dict[c-'a'];
        }
        root->isEndOfWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word,this);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */