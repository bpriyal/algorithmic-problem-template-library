class Solution {
    unordered_map<string, vector<string>> cache;
    unordered_set<string> visited;
    void dfs(const string& email, vector<string>& mergedAccounts) {
      if (visited.count(email)) return;
      mergedAccounts.emplace_back(email);
      visited.emplace(email);
      for (const auto& e : cache[email]) {
        dfs(e, mergedAccounts);
      }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      int size = accounts.size();
      for (const auto& account : accounts) {
        for (int i = 2; i < account.size(); ++i) {
          cache[account[1]].emplace_back(account[i]);
          cache[account[i]].emplace_back(account[1]);
        }
      }

      vector<vector<string>> result;
      for (const auto& account : accounts) {
        vector<string> mergedAccounts;
        const auto& name = account[0];
        const auto& firstEmail = account[1];
        if (!visited.count(firstEmail)) {
          mergedAccounts.emplace_back(name);
          dfs(firstEmail, mergedAccounts);
          sort(mergedAccounts.begin() + 1, mergedAccounts.end());
          result.emplace_back(mergedAccounts);
        }
      }
      return result;
    }
};