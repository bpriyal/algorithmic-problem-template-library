class Solution {
    /*void print(vector<int> &a,vector<int> &b,int n) {
        cout<<"*********"<<"\n";
        for (int i = 0;i<=n;++i) {
            cout<<a[i]<<" ";
        }
        cout<<"\n"<<endl;
        for (int i = 0;i<=n;++i) {
            cout<<b[i]<<" ";
        }
    }*/
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ants = left.size()+right.size();
        vector<int> a(n+1,0);
        vector<int> b(n+1,0);
        for(auto &x:right) {
            a[x] = 1;
        }
        for(auto &x:left) {
            b[x] = 1; 
        }
        int time = 0;
        while(true) {
            time++;
            //print(a,b,n);
            for(int i =0;i<n;++i) {
                if (a[i] > 0) {
                    ++a[i+1];
                    --a[i];
                }
            }
            for(int i = 1;i<=n;++i) {
                if (b[i] > 0) {
                    ++b[i-1];
                    --b[i];
                }
            }
            //print(a,b,n);
            if (a[n]+b[0] == ants) {
                return time;
            }
        }
    }
};