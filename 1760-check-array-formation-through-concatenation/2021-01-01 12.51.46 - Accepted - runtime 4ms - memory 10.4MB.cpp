class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int size = arr.size();
        int i = 0;
        while (i < size) {
            bool match = false;
            for(int j = 0;j < pieces.size();++j) {
                if (arr[i] == pieces[j][0]) {
                    //cout<<pieces[j][0]<<endl;
                    ++i;
                    match = true;
                    for(int k = 1;k < pieces[j].size();++k) {
                        //cout<<"heree"<<endl;
                        if (arr[i] != pieces[j][k]) {
                            return false;
                        }
                        ++i;
                    }
                    break;
                }
            }
            if (!match) {
                return false;
            }
        }
        return true;
    }
};