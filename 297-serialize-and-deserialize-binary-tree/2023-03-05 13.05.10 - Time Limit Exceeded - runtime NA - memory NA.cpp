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
    static const int nullVal = 1001;
    void serializeHelper(TreeNode* root, vector<int>& cache, int position) {
        if (!root) {
            cache[position] = nullVal;
            return;
        }
        cache[position] = root->val;
        cout<<"root->val: "<<root->val<<endl;
        cout<<"position: "<<position<<endl;
        cache[0] = max(cache[0], position);
        serializeHelper(root->left, cache, 2 * position);
        serializeHelper(root->right, cache, 2 * position + 1);
    }

    TreeNode* deserializeHelper(const vector<int>& cache, int position) {
        if (position >= cache.size() || cache[position] == nullVal) return nullptr;
        cout<<"pos ele: "<<cache[position]<<endl;
        TreeNode* node = new TreeNode(cache[position]);

        node->left = deserializeHelper(cache, 2 * position);
        node->right = deserializeHelper(cache, 2 * position + 1);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        vector<int> cache(1e8, 0);
        serializeHelper(root, cache, 1);
        string serializedBT;
        for (int i = 1; i <= cache[0]; ++i) serializedBT += to_string(cache[i]) + ' ';
        serializedBT.pop_back();
        return serializedBT;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<<"data: "<<data<<endl;
        if (data.empty()) return nullptr;
        stringstream ss(data);
        string word;
        vector<int> cache;
        cache.push_back(-1);
        while (ss >> word) {
            cache.push_back(stoi(word));
        }
        cout<<"sdvsdv"<<endl;
        return deserializeHelper(cache, 1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));