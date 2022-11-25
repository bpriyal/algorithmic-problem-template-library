class Solution {
    int diffBetweenStrings(const string& first, const string& second) {
        int diff = 0;
        cout<<"before"<<endl;
        for (int i = 0; i < first.size(); ++i) if (first[i] != second[i]) ++diff;
        cout<<"after"<<endl;
        return diff;
    }
    int util(const string& startGene, const string& endGene, const vector<string>& bank, vector<bool>& visited) {
        cout<<"here"<<endl;
        if (startGene == endGene) return 0;
        int result = INT_MAX;
        for (int i = 0; i < bank.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                result = min(result, util(bank[i], endGene, bank, visited) + diffBetweenStrings(bank[i], startGene));
                visited[i] = false;
            }
        }

        return result == INT_MAX? -INT_MAX : result;

    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        //unordered_set<string> bankCache(bank.begin(), bank.end());
        //bankCache.insert(startGene);

        vector<bool> visited(bank.size(), false);


        int result = util(startGene, endGene, bank, visited);

        return result == INT_MAX? -1 : result;
    }
};