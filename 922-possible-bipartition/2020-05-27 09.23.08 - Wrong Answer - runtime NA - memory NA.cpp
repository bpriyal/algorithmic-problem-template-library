class Solution {
public:
    vector<int> first;
    vector<int> second;
    
    void addPerson(int f,int s) {
        if (first[f-1] == -1 && second[f-1] == -1) {
            if (first[s-1] == -1) {
                first[f-1] = 1;
            } else {
                second[f-1] = 1;
            }
        }
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if (N <= 2) return true;
        first.resize(N,-1);
        second.resize(N,-1);
        for(auto &ele : dislikes) {
            addPerson(ele[0],ele[1]);
            addPerson(ele[1],ele[0]);
            if ((first[ele[0]-1] != -1 && first[ele[1]-1] != -1) || (second[ele[0]-1] != -1 && second[ele[1]-1] != -1)) 
            {
                return false;
            }
        }
        return true;
    }
};