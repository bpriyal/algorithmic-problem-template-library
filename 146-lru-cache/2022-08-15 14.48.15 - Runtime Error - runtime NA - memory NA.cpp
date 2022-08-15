class Node { 
public:
    pair<int, int> val;
    Node *left, *right; 
    
    Node() : left(nullptr), right(nullptr) {}
    explicit Node(pair<int, int> value) : val(value), left(nullptr), right(nullptr) {}
};

class LRUCache {
    Node *current, *head;
    unordered_map<int, Node*> cache;
    int capacity;
    int size;
public:
    LRUCache(int capacity) {
        this->current = this->head = nullptr;
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        cout<<"In Get: "<<key<<endl;
        if (const auto it = cache.find(key); it != cache.end()) {
            cout<<current->val.first<<endl;
            if (size == 1 || current == it->second) return it->second->val.second;
            cout<<"here1"<<endl;
            Node* temp = it->second;
            
            if (!temp->left) {
                cout<<"here3"<<endl;
                head = head->right;
            }
            else {
                cout<<"here4"<<endl;
                temp->left->right = temp->right;
            }
            cout<<"here2"<<endl;
            
            current->right = temp;
            temp->left = current;
            current = temp;
            return it->second->val.second;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        const auto& it = cache.find(key);
        
        if (it == cache.end()) {
            
            if (size == capacity) {
                cache.erase(head->val.first);
                Node* temp = head;
                
                if (current == head) {
                    current = current->right;
                }
                head = head->right;
                if (head) head->left = nullptr;
                
                temp->left = temp->right = nullptr;
                delete temp;
                temp = nullptr;
                
                --size;
            }
            
            Node* temp = new Node(std::make_pair(key, value));
            
            if (head) {
                temp->left = current;
                current->right = temp;
                current = current->right;
            }
            else {
                current = head = temp;
                current->left = head->left = nullptr;
            }
            
            cache.emplace(key, temp);
            ++size;
        }
        else {
            cout<<"key:"<<key<<", value:"<<value<<endl;
            Node* temp = it->second;
            temp->val = std::make_pair(key, value);
            if (size == 1) {
                return;
            }
            
            if (!temp->left) {
                head = head->right;
                if (head) head->left = nullptr;
            }
            else temp->left->right = temp->right;
            
            current->right = temp;
            temp->left = current;
            current = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */