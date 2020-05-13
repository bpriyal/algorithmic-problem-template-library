class Solution {
public:
    /*void del_lead_zero(string& num) {
        int i = 0;
        while (num[i] == '0') ++i;
        num.erase(0,i);
        return;
    }
    string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int size = num.size();
        if (size == k) return "0";
        
        int count = k;
        while(count > 0) {
            bool flag = false;
            for (auto it = num.begin();it<num.end()-1;++it) {
                if (*it > *(it+1)) {
                    num.erase(it);
                    flag = true;
                    break;
                }
            }
            if (!flag) num.erase(num.begin()+num.size()-1);
            --count;
        }
        del_lead_zero(num);
        if (num.size() == 0) return "0";
        return num;
    }*/
    string removeKdigits(string num, int k) {
        string ans="";
        for(auto i:num){
            while(ans.length() && ans.back()>i && k){
                ans.pop_back();
                --k;
            }
            if(ans.length() || i!='0')
                ans+=i;
        }
        while(k--&&ans.length())
            ans.pop_back();
        return ans.length()?ans:"0";
    }
};