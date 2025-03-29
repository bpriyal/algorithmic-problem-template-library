class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      int size = accounts.size();
      unordered_map<string, vector<set<string>>> cache;

      for (const auto& account : accounts) {
        auto it = cache.find(account[0]);
        if (it != cache.end()) {
          int j = 0;
          int sets = it->second.size();
          for (int i = 1; i < account.size(); ++i) {
            for (j = 0; j < sets; ++j) {
              if (it->second[j].count(account[i])) {
                break;
              }
            }
            if (j != sets) break;
          }
          if (j != sets) {
            for (int i = 1; i < account.size(); ++i) it->second[j].emplace(account[i]);
          } else {
            it->second.emplace_back(set<string>(account.begin() + 1, account.end()));
          }
        } else {
          auto [itr, success] = cache.try_emplace(account[0], vector<set<string>>());
          itr->second.emplace_back(set<string>(account.begin() + 1, account.end()));
        }
      }

      vector<vector<string>> result;
      for (const auto& [name, listOfEmails] : cache) {
        for (const auto& emails : listOfEmails) {
          result.emplace_back(vector<string>{name});
          result.back().insert(result.back().end(), emails.begin(), emails.end());
        }
      }

      return result;
    }
};