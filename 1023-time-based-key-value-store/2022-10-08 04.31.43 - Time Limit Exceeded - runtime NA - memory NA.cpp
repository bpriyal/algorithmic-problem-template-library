class Node {
  public:
    pair<int ,string> val;
    Node* left;
    Node* right;
    
    explicit Node(pair<int, string> value) : val(value), left(nullptr), right(nullptr) {}
};

class TimeMap {
    unordered_map<string, Node*> store;
    
    Node* addElement(Node* root, const pair<int, string>& value) {
        if (!root) return new Node(value);
        
        if (root->val.first < value.first) {
            root->right = addElement(root->right, value);
        } else if (root->val.first < value.first) {
            root->left = addElement(root->left, value);  
        } else {
            root->val.second = value.second;
        }
        
        return root;
    }
    
    void getElement(const Node* root, const int timestamp, string& result) {
        if (!root) {
            return;
        }
        
        if (root->val.first <= timestamp)
            result = root->val.second;
        
        if (root->val.first == timestamp) {
            return;
        } else if (root->val.first > timestamp) {
            getElement(root->left, timestamp, result);
        } else {
            getElement(root->right, timestamp, result);
        }
    }
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (store.find(key) == store.end()) {
            store.emplace(key, new Node(std::make_pair(timestamp, value)));
        } else {
            addElement(store[key], make_pair(timestamp, value));
        }
    }
    
    string get(string key, int timestamp) {
        string result = "";
            
        if (store.find(key) != store.end()) {
            getElement(store[key], timestamp, result);
        }
        
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */