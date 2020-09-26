class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(),nums.end(),[](const int &x,const int &y) {
           vector<int> av,bv;
            //printf("%d||%d\n",x,y);
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
            int i=av.size()-1,j = bv.size()-1;
            //cout<<"**"<<endl;
            while(i >= 0 && j >= 0) {
                //printf("vector:%d||%d\n",av[i],bv[j]);
                if (av[i] < bv[j]) {
                    //cout<<"true"<<endl;
                    return false;
                } else if (av[i] > bv[j]) {
                    //cout<<"false"<<endl;
                    return true;
                } else {
                    if (i > 0) {
                        --i;
                    }
                    if (j > 0) {
                        --j;
                    }
                }
            }
            //cout<<"here"<<endl;
            return false;
        });
        string result = "";
        for(int n:nums) {
           // cout<<n<<endl;
            result += to_string(n);
        }
        return result;
    }
};