class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>> cache = {{"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}};

        string result = "";
        for(int i = 0;num != 0;++i) {
            while(num >= cache[i].second) {
                num -= cache[i].second;
                result += cache[i].first;
                //cout<<result<<endl;
            }
        }
        
        return result;
    }
};