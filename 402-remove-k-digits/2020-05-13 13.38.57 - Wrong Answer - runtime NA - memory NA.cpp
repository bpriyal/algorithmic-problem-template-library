class Solution {
public:
    void del_lead_zero(string& num) {
        int i = 0;
        while (num[i] == '0') ++i;
        num.erase(0,i);
        return;
    }
    string removeKdigits(string num, int k) {
        int size = num.size();
        if (size == k) return "0";
        
        int count = k;
        bool flag = false;
        while(count > 0) {
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
    }
};