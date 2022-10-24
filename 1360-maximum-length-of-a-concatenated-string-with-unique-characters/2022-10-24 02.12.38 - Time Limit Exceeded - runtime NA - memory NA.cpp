class Solution {
    int result;
    int size;
    
    int getCacheSize(const vector<int>& cache) {
        int result = 0;
        
        for (int frequency : cache) result += frequency;
        
        return result;
    }
    
    pair<bool, vector<int>> uniqueStrings(const string& s, vector<int>& cache) {
        vector<int> temp(cache);
        
        for (char c : s) {
            ++temp[c - 'a'];
        }
        
        for (int frequency : temp) {
            if (frequency > 1) return { false, cache };
        }
        
        return { true, temp };
    }
    
    pair<bool, vector<int>> getNewCache(const string& s) {
        vector<int> cache(26);
        for (char c : s) {
            ++cache[c - 'a'];
            
            if (cache[c - 'a'] > 1) return { false, cache };
        }
        
        return { true, cache };
    }
    
    void util(const vector<string>& arr, int i, vector<int>& cache) {
        if (i >= size) {
            result = max(result, getCacheSize(cache));
            return;
        }
        
        if (auto [isUnique, freqVector] = getNewCache(arr[i]); isUnique) {
            // cout<<"1:"<<arr[i]<<endl;
            util(arr, i + 1, freqVector); // start afresh
        }
        // cout<<"before: "<<getCacheSize(cache)<<endl;
        if (auto [isUnique, freqVector] = uniqueStrings(arr[i], cache); isUnique) {
            // cout<<"2:"<<arr[i]<<", cacheSize:"<<getCacheSize(freqVector)<<endl;
            util(arr, i + 1, freqVector);
        }
        util(arr, i + 1, cache);
    }
public:
    int maxLength(vector<string>& arr) {
        size = arr.size();
        result = 0;
        
        vector<int> newCache(26);
        util(arr, 0, newCache);
        
        return result;
    }
};