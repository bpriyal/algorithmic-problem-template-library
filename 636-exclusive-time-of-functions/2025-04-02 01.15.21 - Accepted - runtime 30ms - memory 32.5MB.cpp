class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
      int size = logs.size();

      vector<vector<string>> logSplit;
      for (int i = 0; i < size; ++i) {
        std::stringstream ss(logs[i]);
        string token;
        vector<string> tokens;
        while (std::getline(ss, token, ':')) {
          tokens.emplace_back(token);
        }
        logSplit.emplace_back(tokens);
      }
      vector<int> time(n, 0);
      stack<int> st;
      st.emplace(stoi(logSplit[0][0]));
      int i = 1;
      int prevTime = stoi(logSplit[0][2]);
      while (i < size) {
        auto localTime = stoi(logSplit[i][2]);
        if (logSplit[i][1] == "start") {
          if (!st.empty()) time[st.top()] += localTime - prevTime;
          st.emplace(stoi(logSplit[i][0]));
          prevTime = localTime;
        } else {
          time[st.top()] += localTime + 1 - prevTime;
          st.pop();
          prevTime = localTime + 1;
        }
        ++i;
      }

      return time;
    }
};