class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> candy(num_people,0);
        int index=0,n=0;
        while(candies > 0) {
            ++n;
            if (candies < n) {
                //cout<<"here"<<endl;
                candy[index%num_people] += candies;
                break;
            }
            candies -= n;
            //cout<<"before"<<index%n<<endl;
            candy[(index%num_people)] += n;
            //cout<<"after"<<index%n<<endl;
            ++index;
        }
        return candy;
    }
};