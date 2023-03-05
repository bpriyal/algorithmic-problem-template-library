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
    void serializeHelper(ostringstream& out, TreeNode* root) {
        if (!root) {
            out << "# ";
            return;
        }
        out << root->val << " ";
        serializeHelper(out, root->left);
        serializeHelper(out, root->right);
    }

    TreeNode* deserializeHelper(istringstream& in) {
        string num;
        in >> num;
        if (num == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(num));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(out, root);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));