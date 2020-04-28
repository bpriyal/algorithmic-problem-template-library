class FirstUnique {
public:
    list<int> queue;
    map<int,list<int>::iterator> hashmap;
    FirstUnique(vector<int>& nums) {
        for (auto i:nums) {
            add(i);
        }
    }
    
    int showFirstUnique() {
        if (queue.size() == 0) return -1;
        return queue.back();
    }
    
    void add(int value) {
        if (hashmap.find(value) == hashmap.end()) {
            cout<<"ADD:"<<value<<endl;
            queue.push_front(value);
            hashmap[value] = queue.begin();
        } else {
            cout<<"ADD:ERASE:"<<value<<endl;
            cout<<*hashmap[value]<<endl;
            queue.erase(hashmap[value]);
            cout<<"AFTER ERASE"<<endl;
            cout<<queue.back()<<endl;
           // hashmap[value] = queue.begin();
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */