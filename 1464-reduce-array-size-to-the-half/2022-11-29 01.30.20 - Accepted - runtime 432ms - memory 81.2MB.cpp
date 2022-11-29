class Solution {
public:
    int minSetSize(vector<int>& arr) {
       unordered_map<int, int> frequencyCache;
       int result = 0;
       int initialSize = arr.size();
       int resultantSize = initialSize;

       for (int num : arr) ++frequencyCache[num]; // O(n)

        vector<pair<int, int>> highestFrequency;

        for(auto it = frequencyCache.begin(); it != frequencyCache.end(); ++it) highestFrequency.emplace_back(it->first, it->second); // O(k)

        sort(highestFrequency.begin(), highestFrequency.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second > p2.second;
        }); // O(klogk)

        for (auto it : highestFrequency) { // O(K)
            resultantSize -= it.second;
            ++result;
            if (resultantSize <= initialSize/2) break;
        }

        return result;
    }
};

// Time - K log K, k = unique elements
// Space - O(2K)