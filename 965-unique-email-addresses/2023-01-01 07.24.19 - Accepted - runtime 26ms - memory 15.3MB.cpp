class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int size = emails.size();
        unordered_set<string> cache;

        for (int i = 0; i < size; ++i) {
            const string& strClone = emails.at(i);
            auto atCharPos = strClone.find('@', 0);
            if (atCharPos != string::npos) {
                string localName = strClone.substr(0, atCharPos);
                string domainName = strClone.substr(atCharPos);

                int localNameSize = localName.size();
                string temp = "";
                
                for (int i = 0; i < localNameSize && localName[i] != '+'; ++i) {
                    if (localName[i] == '.') continue;
                    temp += localName[i];
                }

                cache.emplace(temp + domainName);
            }
        }

        return cache.size();
    }
};