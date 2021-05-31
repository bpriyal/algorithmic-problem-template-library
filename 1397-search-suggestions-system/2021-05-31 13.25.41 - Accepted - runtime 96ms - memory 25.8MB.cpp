class Solution {
    bool isMatch(const string &product,const string &key) {
        //cout<<product.substr(0,key.size())<<"-"<<key<<endl;
        return product.substr(0,key.size()) == key;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        int size = products.size();
        
        sort(products.begin(),products.end());
        
        string prefix = "";
        int start;
        int bsstart = 0;
        
        for(char c:searchWord) {
            prefix += c;
            
            start = lower_bound(products.begin()+bsstart,products.end(),prefix) - products.begin();
            
            result.push_back({});
            
            for(int i = start;i < min(start+3,size);++i) {
                if (isMatch(products[i],prefix)) {
                    result.back().push_back(products[i]);
                } else {
                    break;
                }
            }
            
            bsstart = start;
        }
        
        return result;
    }
};