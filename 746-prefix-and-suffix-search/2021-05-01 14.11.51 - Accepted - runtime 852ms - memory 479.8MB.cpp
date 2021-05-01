class WordFilter {
    class Trie {
    public: 
        vector<int> indexes;
        Trie *node[27];
        bool isLeaf;
        
        Trie() {
            isLeaf = false;
            
            for(int i = 0;i < 27;++i) {
                node[i] = nullptr;
            }
        }
        
        ~Trie() {
            for(int i = 0;i < 27;++i) {
                delete node[i];
                node[i] = nullptr;
            }
        }
        
        void insert(string word,int index) {
            int size = word.size();
            int i = 0;
            Trie *root = this;
            
            while (i < size) {
                if (root->node[word[i]-'a'] == nullptr) {
                    root->node[word[i]-'a'] = new Trie();
                }
                root->indexes.push_back(index);
                root = root->node[word[i]-'a'];
                ++i;
            }
            root->indexes.push_back(index);
    
            root->isLeaf = true;
        }
        
        vector<int> search(string word) {
            int size = word.size();
            Trie *root = this;
            
            for(int i = 0;i < size;++i) {
                if (!root->node[word[i]-'a']) {
                    return {};
                }
                root = root->node[word[i]-'a'];
            }
            return root->indexes;
        }
        
    };
public:
    Trie *head;
    WordFilter(vector<string>& words) {
        head = new Trie();
        int index = 0;
        for(const string &word:words) {
            int size = word.size();
            for(int i = 0;i < size;++i) {
                string temp = word.substr(size-i-1) + '{' + word;
                head->insert(temp,index);
            }
            
            ++index;
        }
    }
    
    int f(string prefix, string suffix) {
        int _max = INT_MIN;
        for(int index:head->search(suffix+'{'+prefix)) {
            _max = max(_max,index);
        }
        
        return _max == INT_MIN? -1:_max;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */