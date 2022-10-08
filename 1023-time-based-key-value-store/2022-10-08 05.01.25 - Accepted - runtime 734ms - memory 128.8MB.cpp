using timeValuePair = pair<int, string>;
class TimeMap {
    unordered_map<string, vector<timeValuePair>> store;
    
    void getMatchingOrSmaller(const vector<timeValuePair>& vp, int timestamp, string& result) {
        int h = vp.size() - 1;
        int l = 0;
        
        while (l <= h) {
            int mid = l + (h - l)/2;
            
            if (timestamp >= vp[mid].first) result = vp[mid].second;
            
            if (timestamp == vp[mid].first) return;
            else if (timestamp > vp[mid].first) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
    }
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeValuePair p({timestamp, value});
        
        if (store.find(key) == store.end()) {
            store.emplace(key, vector<timeValuePair>{p});    
        } else {
            store[key].push_back(p);
        }
    }
    
    string get(string key, int timestamp) {
        string result = "";
        
        if (store.find(key) != store.end()) {
            getMatchingOrSmaller(store[key], timestamp, result);
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