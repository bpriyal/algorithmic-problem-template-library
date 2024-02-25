class Comp {
  public:
    bool operator()(const pair<char, int> p1, const pair<char, int> p2) {
        if (p1.second < p2.second) return true;
        else if (p1.second > p2.second) return false;
        else return p1.first < p2.first;
    }
};
class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0) return s;
        // sort(s.rbegin(), s.rend());
        priority_queue<pair<char, int>, vector<pair<char, int>>, Comp> pq;
        unordered_map<char, int> cache;
        for (char c : s) ++cache[c];
        for (const auto& [ch, frequency] : cache) pq.emplace(ch, frequency);

        string result = "";

        while (!pq.empty()) {
            vector<pair<char, int>> temp;
            for (int i = 0; i < k; ++i) {
                if (pq.empty()) {
                    cout<<result<<endl;
                    return temp.empty()? result : "";
                }
                auto [ch, frequency] = pq.top(); pq.pop();
                result += ch;
                --frequency;
                if (frequency != 0) temp.emplace_back(ch, frequency);
            }
            for (const auto& [ch, frequency] : temp) pq.emplace(ch, frequency);
        }
        return result;
    }
};