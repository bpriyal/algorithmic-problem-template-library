class TrieNode {
  public:
    vector<TrieNode*> children;
    bool isLeaf;
    
    TrieNode() {
        isLeaf = false;
        children.resize(26, nullptr);
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
        
    void insert(string word) {
        int size = word.size();
        int i = 0;
        TrieNode* temp2 = root;
        while (i < size) {
            // TrieNode* temp = temp2->children[word[i] - 'a'];
            if (!temp2->children[word[i] - 'a']) {
                temp2->children[word[i] - 'a'] = new TrieNode();
            }
            temp2 = temp2->children[word[i] - 'a'];
            ++i;
        }
        
        temp2->isLeaf = true;
    }
    
    bool search(string word) {
        int size = word.size();
        int i = 0;
        TrieNode* temp2 = root;
        while (i < size) {
            TrieNode* temp = temp2->children[word[i] - 'a'];
            if (!temp) return false;
            temp2 = temp;
            ++i;
        }
        return temp2->isLeaf;
    }
    
    bool startsWith(string prefix) {
        int size = prefix.size();
        int i = 0;
        TrieNode* temp2 = root;
        while (i < size) {
            TrieNode* temp = temp2->children[prefix[i] - 'a'];
            if (!temp) return false;
            temp2 = temp;
            ++i;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */