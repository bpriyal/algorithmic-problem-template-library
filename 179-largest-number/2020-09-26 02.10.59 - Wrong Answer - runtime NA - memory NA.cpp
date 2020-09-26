class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(),nums.end(),[](const int &x,const int &y) {
           vector<int> av,bv;
            int a = x;
            int b = y;
            while(a != 0) {
                av.push_back(a%10);
                a /= 10;
            }
            while(b != 0) {
                bv.push_back(b%10);
                b /= 10;
            }
            int i=0,j = 0;
            //cout<<"**"<<endl;
            while(i < av.size() && j < bv.size()) {
                if (av[i] < bv[j]) {
                    return false;
                } else if (av[i] > bv[j]) {
                    return true;
                } else {
                    if (i < av.size()-1) {
                        ++i;
                    }
                    if (j < av.size()-1) {
                        ++j;
                    }
                }
            }
            //cout<<"here"<<endl;
            return false;
        });
        string result = "";
        for(int n:nums) {
            //cout<<n<<endl;
            result += to_string(n);
        }
        return result;
    }
};