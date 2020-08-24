class Trie {
public:
    Trie *children[26];
    bool isEndofWord;
    /** Initialize your data structure here. */
    Trie() {
        for (int i=0;i<26;++i) {
            children[i] = nullptr;
        }
        isEndofWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int size = word.size();
        Trie *root = this;
        for(int i=0;i<size;++i) {
            if(!root->children[word[i]-'a']) {
                root->children[word[i]-'a'] = new Trie();
            }
            root = root->children[word[i]-'a'];
        }
        root->isEndofWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
       Trie *root = this;
        int size = word.size();
        for (int i=0;i<size;++i) {
            if (!root->children[word[i]-'a']) return false;
            root = root->children[word[i]-'a'];
        }
        return root->isEndofWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *root = this;
        int size = prefix.size();
        for (int i=0;i<size;++i) {
            if (!root->children[prefix[i]-'a']) return false;
            root = root->children[prefix[i]-'a'];
        }
        return true;
    }
    
    bool check(string &s, int st, int len) {
            Trie *root = this;
            for(int it = st; it>st-len; it--) {
                int index = s[it]-'a';
                if(root->children[index] == nullptr)
                    return false;
                root = root->children[index];
                if (root->isEndofWord)  return true;
            }
            return root->isEndofWord;
        }
};
class StreamChecker {
    Trie *root;
    string temp;
    int _max,_min;
public:
    StreamChecker(vector<string>& words) {
        root = new Trie;
        _max = 0, _min = INT_MAX;
        for(auto it: words){
            root->insert(it);
            _min = _min > it.size() ? it.size() : _min;
            _max= _max < it.size() ? it.size() : _max;
        }
    }
    
    bool query(char letter) {
        temp += letter;
        if(temp.size() < _min) return false;
        int len = min<long>(_max, temp.size());
        return root->check(temp, temp.size()-1, len);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */