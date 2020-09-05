class Solution {
public:
    vector<int> partitionLabels(string S) {
        int size = S.size();
        vector<int> lastPos(26);
        //cout<<"000"<<endl;
        for(int i = 0;i<size;++i) {
            lastPos[S[i]-'a'] = i;
        }
        //cout<<"here"<<endl;
        vector<int> result;
        int i=0,j;
        while(i < size) {
            int sizeP = 0;
            j = lastPos[S[i]-'a'];
            ++i;
            ++sizeP;
            while(i<=j) {
                if (lastPos[S[i]-'a'] < j) {
                    ++i;
                    ++sizeP;
                    continue;
                }
                j = lastPos[S[i]-'a'];
                ++i;
                ++sizeP;
            }
            result.push_back(sizeP);
            i = j + 1;
        }
        return result;
    }
};