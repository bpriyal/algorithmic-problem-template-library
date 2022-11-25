class Solution {
    int util(const string& startGene, const string& endGene, const unordered_set<string>& bankCache, const vector<int>& diffIndexes, vector<bool>& visited) {
        if (!bankCache.count(startGene)) return INT_MAX;
        if (startGene == endGene) return 0;

        int result = INT_MAX;

        for (int index : diffIndexes) {
            if (!visited[index]) {
                string temp = startGene;
                temp[index] = endGene[index];

                visited[index] = true;
                result = min(result, util(temp, endGene, bankCache, diffIndexes, visited));
                visited[index] = false;
            }
        }

        return result == INT_MAX? INT_MAX : result + 1;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<int> diffIndexes;
        unordered_set<string> bankCache(bank.begin(), bank.end());
        bankCache.insert(startGene);

        vector<bool> visited(8, false);

        for (int i = 0; i < 8; ++i) {
            if (startGene[i] != endGene[i]) diffIndexes.emplace_back(i);
        }

        int result = util(startGene, endGene, bankCache, diffIndexes, visited);

        return result == INT_MAX? -1 : result;
    }
};