class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        int size = candyType.size();
        for(int candy:candyType) {
            s.insert(candy);
        }
        
        return s.size() >= size/2 ? size/2 : s.size();
    }
};