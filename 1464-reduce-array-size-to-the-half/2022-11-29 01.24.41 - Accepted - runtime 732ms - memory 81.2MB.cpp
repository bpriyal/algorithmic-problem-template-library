class Solution {
public:
    int minSetSize(vector<int>& arr) {
       unordered_map<int, int> frequencyCache;
       int result = 0;
       int initialSize = arr.size();
       int resultantSize = initialSize;

       for (int num : arr) ++frequencyCache[num];

        vector<pair<int, int>> highestFrequency;

        for(auto it = frequencyCache.begin(); it != frequencyCache.end(); ++it) highestFrequency.emplace_back(it->first, it->second);

        sort(highestFrequency.begin(), highestFrequency.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second > p2.second;
        });

        for (auto it : highestFrequency) {
            cout<<it.first<<", "<<it.second<<endl;
            resultantSize -= it.second;
            ++result;
            if (resultantSize <= initialSize/2) break;
        }

        return result;
    }
};