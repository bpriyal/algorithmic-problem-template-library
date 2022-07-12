class Solution {
    int size;
    bool util(vector<int>& matchsticks,int s1, int s2, int s3, int s4, int i) {
        if (i == size) {
            cout<<s1<<"\t"<<s2<<"\t"<<s3<<"\t"<<s4<<endl;
            return s1 == s2 && s2 == s3 && s3 == s4;
        }
                
        return util(matchsticks, s1 + matchsticks[i], s2, s3, s4, i + 1) || util(matchsticks, s1, s2 + matchsticks[i], s3, s4, i + 1) || util(matchsticks, s1, s2, s3 + matchsticks[i], s4, i + 1) || util(matchsticks, s1, s2, s3, s4 + matchsticks[i], i + 1);
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        size = matchsticks.size();
        
        return util(matchsticks, 0, 0, 0, 0, 0);
    }
};