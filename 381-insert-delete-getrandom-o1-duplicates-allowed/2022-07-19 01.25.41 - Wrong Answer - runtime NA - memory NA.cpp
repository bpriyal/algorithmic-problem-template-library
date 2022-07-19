class RandomizedCollection {
public:
    struct listNode{
        int data;
        listNode* prev;
        listNode* next;
        listNode(int d) : data(d), prev(NULL), next(NULL) {};
    };
    
    listNode *head, *tail, *rItr;
    unordered_map<int, list<listNode*>> m;
    RandomizedCollection() {
        head = tail = rItr = NULL;
        m.clear();
    };
    
    bool insert(int val) {
        listNode* tmp = new listNode(val);
        if (head == NULL) {
            head = tail = rItr = tmp;
        } else {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        
        m[val].push_back(tmp);
        return (m[val].size() == 1);
    };
    
    void removeEntry(listNode** head, listNode** tail, listNode** rItr, listNode* node) {
        
        if ((*head) == node) {
            (*head) = (*head)->next;
        }
        
        if ((*tail) == node) {
            (*tail) = (*tail)->prev;
        }
        
        if (node->prev) {
            node->prev->next = node->next;
        }
        
        if (node->next) {
            node->next->prev = node->prev;
        }
        
        if ((*rItr) == node) {
            (*rItr) = (*rItr)->prev;
        }
    };
    
    bool remove(int val) {
        if (m.find(val) == m.end())
            return false;
        
        listNode* tmp = m[val].back();
        m[val].pop_back();
        removeEntry(&head, &tail, &rItr, tmp);
        
        if (m[val].size() == 0)
            m.erase(val);
        
        return true;
    };
    
    int getRandom() {
        
        if (rItr == NULL) {
            rItr = head;
        }
        int tmp = rItr->data;
        rItr = rItr->next;
        return tmp;
    };
};
/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */