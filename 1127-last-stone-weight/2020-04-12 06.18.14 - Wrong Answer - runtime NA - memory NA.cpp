class Solution {
public:
    int size;
    vector<int>::iterator it;
    int lastStoneWeight(vector<int>& stones) {
        while((size=stones.size()) > 1){
            sort(stones.begin(),stones.end());
            //cout<<stones[size-1]<<endl;
            it=stones.end();
            if (stones[size-2] == stones[size-1]){
                stones.erase(it-2,it);
                //cout<<stones[stones.size()-1]<<endl;
            } else {
                int newstone;
                newstone = stones[size-2] > stones[size-1] ? stones[size-2]-stones[size-1] : stones[size-1]-stones[size-2];
                stones.erase(it-2,it);
                stones.push_back(newstone);   
            }
        }
        if (size = 0) {
            return 0;
        }
        return stones[0];
    }
};