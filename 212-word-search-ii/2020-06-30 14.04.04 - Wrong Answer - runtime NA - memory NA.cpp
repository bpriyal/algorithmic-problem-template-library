class Trie {
public: 
    Trie *node[26];
    bool isEnd;
    Trie() {
        for(int i=0;i<26;++i) {
            node[i] = nullptr;
        }
        isEnd = false;
    }
    void insert(string word) {
        Trie *root = this;
        for(int i=0;i<word.size();++i) {
            if (!root->node[word[i]-'a']) {
                root->node[word[i]-'a'] = new Trie();
            }
            root = root->node[word[i]-'a'];
        }
        root->isEnd = true;
    }
    /*bool search(string word) {
        Trie *root = this;
        for(int i=0;i<word.size();++i) {
            if(!root->node[word[i]-'a']) {
                return false;
            }
            root = root->node[word[i]-'a'];
        }
        return root->isEnd;
    }*/
};
class Solution {
    set<string> result;
    int row,col;
    void dfs(const vector<vector<char>> &board,int i,int j,string run,const Trie *root) {
        if (i < 0 || i>=row ||j<0 ||j>=col) return;
        if (root->node[board[i][j]-'a']) {
            //cout<<run<<endl;
            //cout<<"char:"<<board[i][j]<<endl;
            if (root->node[board[i][j]-'a']->isEnd) {
                //cout<<"here"<<endl;
                result.insert(run+board[i][j]);
                return;
            }
            dfs(board,i+1,j,run+board[i][j],root->node[board[i][j]-'a']);
            dfs(board,i,j+1,run+board[i][j],root->node[board[i][j]-'a']);
            dfs(board,i-1,j,run+board[i][j],root->node[board[i][j]-'a']);
            dfs(board,i,j-1,run+board[i][j],root->node[board[i][j]-'a']);
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = board.size();
        col = board[0].size();
        Trie *root = new Trie();
        for(int i = 0;i<words.size();++i) {
            root->insert(words[i]);
        }
        for(int i=0;i<row;++i) {
            for(int j =0;j<col;++j) {
                dfs(board,i,j,"",root);
            }
        }
        return vector<string>(result.begin(),result.end());
    }
};