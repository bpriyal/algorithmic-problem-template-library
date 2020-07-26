class Solution {
    int min;
    string str;
    int size;
    void util(string s,int i,int counter) {
        //cout<<s<<endl;
        if (counter > min) {
            return;
        }
        if (s == str) {
            //cout<<"here222"<<endl;

            min = counter;
            //cout<<counter<<endl;
            return;
        }
        for(int j=i+1;j<size;++j) {
            string temp = s;
            //cout<<"temp str:"<<temp<<endl;
            for(int k = j;k<size;++k) {
                if (s[k] == '0') {
                    temp[k] = '1';
                } else {
                    temp[k] = '0';
                }
            }
            util(temp,j,counter+1);
        }
        return;
    }
public:
    Solution() : min(INT_MAX){}
    int minFlips(string target) {
        size = target.size();
        str = target;
        string runStr;
        for(int i = 0;i<size;++i) {
            runStr += "0";
        }
        //cout<<"here"<<endl;
        util(runStr,-1,0);
        return min;
    }
};