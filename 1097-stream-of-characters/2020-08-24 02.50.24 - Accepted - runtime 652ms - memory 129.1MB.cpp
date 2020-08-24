class Trie {
    struct Node {
        vector<Node *> children;
        bool isEndOfWord;
        Node():isEndOfWord(false){
            for(int i=0; i<26; i++)
                children.push_back(nullptr);
        }
    };
    Node *head;
    public:
        Trie():head(new Node()) { }
        void insert(string &s) {
            Node *root = head;
            string::reverse_iterator it = s.rbegin();
            for(; it<s.rend(); it++) {
                int index = *it-'a';
                if(root->children[index] == nullptr)
                    root->children[index] = new Node();
                root = root->children[index];
            }
            root->isEndOfWord = true;
        }
        bool check(string &s, int st, int len) {
            Node *root = head;
            for(int it = st; it>st-len; it--) {
                int index = s[it]-'a';
                if(root->children[index] == nullptr)
                    return false;
                root = root->children[index];
                if (root->isEndOfWord)  return true;
            }
            return root->isEndOfWord;
        }
};

class StreamChecker {
public:
    Trie *root;
    string searchStr;
    int _max, _min;

    StreamChecker(vector<string>& words) {
        root = new Trie;
        _max = 0, _min = INT_MAX;
        for(auto it: words){
            root->insert(it);
            _min = _min > it.length() ? it.length() : _min;
            _max = _max < it.length() ? it.length() : _max;
        }
    }

    bool query(char letter) {
        searchStr += letter;
        if(searchStr.length() < _min) return false;
        int len = min<long>(_max, searchStr.length());
        bool status = root->check(searchStr, searchStr.length()-1, len);
        return status;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */