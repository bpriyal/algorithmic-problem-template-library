;class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
      vector<int> times(n, 0);
      stack<int> st;
      int size = logs.size();
      int lastEventTime = 0;
      auto extract = [](const string& log) -> tuple<int, bool, int> {
        stringstream ss;
        ss << log;
        int id, time;
        bool isStart;
        int j = 0;
        string temp;
        while (getline(ss, temp, ':')) {
          if (j == 0) id = stoi(temp);
          else if (j == 1) isStart = temp == "start";
          else if (j == 2) time = stoi(temp);
          ++j;
        }
        return {id, isStart, time};
      };
      for (int i = 0; i < size; ++i) {
        auto [id, isStart, time] = extract(logs[i]);
        if (isStart) {
          if (!st.empty()) times[st.top()] += time - lastEventTime;
          st.emplace(id);
          lastEventTime = time;
        } else {
          times[st.top()] += time - lastEventTime + 1;
          st.pop();
          lastEventTime = time + 1;
        }
      }
      return times;
    }
};