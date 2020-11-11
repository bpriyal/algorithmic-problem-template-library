class Solution {
    int util(vector<int> &p1,vector<int> &p2) {
        return (p2[0]-p1[0])*(p2[0]-p1[0]) + (p2[1]-p1[1])*(p2[1]-p1[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> cache;
        cache.insert(util(p1,p2));
        cache.insert(util(p1,p3));
        cache.insert(util(p1,p4));
        cache.insert(util(p2,p3));
        cache.insert(util(p2,p4));
        cache.insert(util(p3,p4));
        
        return !cache.empty() && cache.size() == 2;
    }
};