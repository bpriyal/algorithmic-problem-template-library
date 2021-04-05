/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    int number(const TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1+number(root->left)+number(root->right);
    }
    
    char preorder(TreeNode *root,char str[],int i) {
        if (root == nullptr) {
            return '.';
        }
        char c = '0'+root->val;
        //str[i] = c;
        str[2*i+1] = preorder(root->left,str,2*i+1);
        //cout<<2*i+1<<" "<<str[2*i+1]<<endl;
        str[2*i+2] = preorder(root->right,str,2*i+2);
        return c;
    }
    
    TreeNode* util(string data,int i) {
        int size = data.size();
        if (data[i] == '.' || data[i] == '-') {
            return nullptr;
        }
        TreeNode* root = new TreeNode();
        root->val = data[i]-'0';
        root->left = util(data,2*i+1);
        root->right = util(data,2*i+2);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        char str[10000];
        for(int i = 0;i < 10000;++i) {
            str[i] = '-';
        }
        str[0] = preorder(root,str,0);
        str[9999] = '\0';
        return str;
    }

    //123..45....

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return util(data,0);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));