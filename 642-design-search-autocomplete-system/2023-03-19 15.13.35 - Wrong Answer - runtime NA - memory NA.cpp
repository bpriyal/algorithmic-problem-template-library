class Trie {
public:
    vector<Trie*> children;
    bool EOW;
    int hotDegree;

    Trie() {
        children.resize(28, nullptr);
        EOW = false;
    }
};
class AutocompleteSystem {
    vector<Trie*> dict;
    string subject;
    Trie* lastEncountered;

    int getDictPos(char c) {
        if (c == '#') return 27;
        else if (c == ' ') return 26;
        else return c - 'a';
    }
    void populateDictionary(const string& sentence, int position, int hotDegree, vector<Trie*>& dict) {
        if (position >= sentence.size()) return;
        int effectivePos = getDictPos(sentence[position]);
        if (!dict[effectivePos]) {
            //cout<<"adding in dict at position:"<<getDictPos(sentence[position])<<endl;
            dict[effectivePos] = new Trie();
        }
        Trie* head = dict[effectivePos];
        if (position == sentence.size() - 1) {
            // cout<<"adding element ending at: "<<sentence[position]<<endl;
            head->EOW = true;
            head->hotDegree = head->hotDegree > 0 ? head->hotDegree + 1 : hotDegree;
        }
        populateDictionary(sentence, position + 1, hotDegree, head->children);
    }

    void getPrefixStr(Trie* head, string& temp, vector<pair<string, int>>& result){
        // cout<<"In getPrefixStr: "<<temp<<endl;
        if (head->EOW) {
            if (result.size() < 3) result.push_back(make_pair(temp, head->hotDegree));
            else if (result.back().second < head->hotDegree || (result.back().second == head->hotDegree && result.back().first > temp)) {
                if (result.size() == 3) result.pop_back();
                result.push_back(make_pair(temp, head->hotDegree));
            }
            cout<<"before sort: "<<endl;
            for (auto &a: result) {
                cout<<a.first<<"\t";
            }cout<<endl;
            sort(result.begin(), result.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
                if (a.second > b.second) return true;
                else if (a.second == b.second) return a.first < b.first;
                return false;
            });
            return;
        }
        for (int i = 0; i < 27; ++i) {
            if (head->children[i]) {
                temp += i == 26 ? ' ' : ('a' + i);
                getPrefixStr(head->children[i], temp, result);
                temp.pop_back();
            }
        }
    }

    vector<string> getMatchingStrings() {
        cout<<"In getMatchStrings(): "<<subject<<endl;
        vector<string> result;
        if (!lastEncountered && subject.size() > 1) {
            cout<<"return empty"<<endl;
            return result;
        }
        if (lastEncountered) {
            cout<<"In valid lastEncounted: "<<getDictPos(subject.back())<<endl;
            lastEncountered = lastEncountered->children[getDictPos(subject.back())];
        } else {
            cout<<"In invalid lastEncounted: "<<getDictPos(subject.back())<<endl;
            lastEncountered = dict[getDictPos(subject.back())];
        }

        if (!lastEncountered) {
            cout<<"still empty"<<endl;
            return result;
        }
        string temp = subject;
        vector<pair<string, int>> pairResult;
        cout<<"********"<<temp<<endl;
        getPrefixStr(lastEncountered, temp, pairResult);
        for (int i = 0; i < pairResult.size(); ++i) result.push_back(pairResult[i].first);
        return result;
    }
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        dict.resize(28, nullptr);
        subject = "";
        lastEncountered = nullptr;
        int size = times.size();
        for (int i = 0; i < size; ++i) {
            // cout<<"Calling first populateDict"<<endl;
            populateDictionary(sentences[i], 0, times[i], dict);
        }
        // for (int i = 0; i < 28; ++i) {
        //     if (dict[i]) cout<<"valid at pos: "<<i<<endl;
        //     else cout<<"invalid at pos: "<<i<<endl;
        // }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            populateDictionary(subject, 0, 1, dict);
            subject = ""; // reset subject string
            lastEncountered = nullptr;
            return vector<string>();
        }
        // for (int i = 0; i < 28; ++i) {
        //     if (dict[i]) cout<<"valid at pos: "<<i<<endl;
        //     else cout<<"invalid at pos: "<<i<<endl;
        // }
        subject += c;
        return getMatchingStrings();
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */