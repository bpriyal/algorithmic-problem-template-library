class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int> cache;
        
        if (s.size() < k) {
            return false;
        }
        
        for(int i = 0;i <= s.size() - k;++i) {
            ++cache[s.substr(i,k)];
        }
        
        int nu = 0;
        for(auto it = cache.begin();it != cache.end();++it) {
            ++nu;
        }
        
        return nu == pow(2,k)? true:false; 
        
        for(int i = 0;i < pow(2,k)-1;++i) {
            string temp = "";
            int num = i;
            //cout<<"number"<<i<<endl;
            while(temp.size() != k) {
                temp += to_string(num%2);
                //cout<<temp<<endl;
                num = num >> 1;
            }
            
            if (cache.find(temp) == cache.end()) {
                //cout<<temp<<endl;
                return false;
            }
        }
        
        return true;
    }
};