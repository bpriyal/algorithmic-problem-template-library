class Node {
  public:
    Node(int val_) : _val(val_) {}
    int _val;
    vector<Node*> _children;
};
class Solution {
    Node* createOrGetNode(int pid_, unordered_map<int, Node*>& cache_) {
        if (pid_ == 0) return nullptr;
        auto it = cache_.find(pid_);
        if (it == cache_.end()) {
            auto [it1, success] = cache_.try_emplace(pid_, new Node(pid_));
            return it1->second;
        }
        return it->second;
    }
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
        for (int i = 0; i < size; ++i) {
            auto* processIdNode = createOrGetNode(pid[i], cache);
            auto* parentProcessIdNode = createOrGetNode(ppid[i], cache);
            if (parentProcessIdNode) parentProcessIdNode->_children.emplace_back(processIdNode);
        }
        vector<int> result;
        _traversal(cache[kill], result);
        return result;
    }
};