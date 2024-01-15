class Node {
  public:
    Node(int val_) : _val(val_) {}
    int _val;
    vector<Node*> _children;
};
class Solution {
    Node* createOrGetNode(int pid_, unordered_map<int, Node*>& cache_) {
        // cout<<"createOrGetNode: "<<pid_<<endl;
        if (pid_ == 0) return nullptr;
        if (!cache_.contains(pid_)) {
            // cout<<"not found"<<endl;
            Node* node = new Node(pid_);
            cache_.try_emplace(pid_, node);
        }
        return cache_[pid_];
    }
    // const Node* _traversal(const Node* root_, int kill_) {
    //     if (!root_) return nullptr;
    //     cout<<"root _val: "<<root_->_val<<endl;
    //     if (root_->_val == kill_) return root_;
    //     for (const auto* child : root_->_children) {
    //         cout<<"child val: "<<child->_val<<endl;
    //         _traversal(child, kill_);
    //     }
    //     return nullptr;
    // }
    void _traversal(const Node* root_, vector<int>& result_) {
        if (!root_) return;
        result_.emplace_back(root_->_val);
        for (const auto* child : root_->_children) {
            _traversal(child, result_);
        }
    }
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int size = pid.size();
        unordered_map<int, Node*> cache;
        Node* root = nullptr;
        for (int i = 0; i < size; ++i) {
            auto* processIdNode = createOrGetNode(pid[i], cache);
            auto* parentProcessIdNode = createOrGetNode(ppid[i], cache);
            // cout<<"**: "<<processIdNode->_val<<endl;
            if (parentProcessIdNode) {
                // cout<<"***: "<<parentProcessIdNode->_val<<endl;
                parentProcessIdNode->_children.emplace_back(processIdNode);
            }
            else {
                root = processIdNode;
                // cout<<"-------: "<<root->_val<<endl;
            }
        }
        vector<int> result;
        // const auto* parentProcessToKillNode = _traversal(root, kill);
        // cout<<parentProcessToKillNode->_val<<endl;
        _traversal(cache[kill], result);
        return result;
    }
};