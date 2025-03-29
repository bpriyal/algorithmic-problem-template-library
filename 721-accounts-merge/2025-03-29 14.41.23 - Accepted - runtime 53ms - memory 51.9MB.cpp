class Solution { 
    unordered_map<string, vector<string>> adjacencyList;
    unordered_set<string> visited;

    void dfs(vector<string>& mergedAccounts, const string& email) {
      if (visited.count(email)) return;
      visited.emplace(email);
      mergedAccounts.emplace_back(email);

      for (const auto& childEmail : adjacencyList[email]) {
        dfs(mergedAccounts, childEmail);
      }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      int size = accounts.size();
      // make adjacencyList
      for (const auto& account : accounts) {
        for (int i = 2; i < account.size(); ++i) {
          adjacencyList[account[1]].emplace_back(account[i]);
          adjacencyList[account[i]].emplace_back(account[1]);
        }
      }

      vector<vector<string>> result;
      for (const auto& account : accounts) {
        const auto& name = account[0];
        const auto& firstEmail = account[1];

        vector<string> mergedAccount;
        if (!visited.count(firstEmail)) {
          mergedAccount.emplace_back(name);
          dfs(mergedAccount, firstEmail);
          sort(mergedAccount.begin() + 1, mergedAccount.end());
          result.emplace_back(mergedAccount);
        }
      }

      return result;
    }
};