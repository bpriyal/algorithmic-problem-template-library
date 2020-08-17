class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> candy(num_people,0);
        int index=0,n=0;
        while(candies > 0) {
            ++n;
            if (candies < n) {
                candy[index%num_people] += candies;
                break;
            }
            candies -= n;
            candy[(index%num_people)] += n;
            ++index;
        }
        return candy;
    }
};