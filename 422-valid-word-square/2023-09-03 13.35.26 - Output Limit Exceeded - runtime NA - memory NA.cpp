class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int rows = words.size();
        int cols = words[0].size();
        if (rows != cols) return false;
        int k = max(rows, cols);
        cout<<k<<endl;
        for (int i = 0; i < k; ++i) {
            cout<<"i: "<<i<<endl;
            string kColStr;
            for (int j = 0; j < rows; ++j) {
                if (i >= words[j].size()) break;
                cout<<words[j]<<endl;
                kColStr += words[j][i];
            }
            if (kColStr != words[i]) {
                cout<<i<<", "<<kColStr<<", "<<endl;
                return false;
            }
        }
        return true;
    }
};