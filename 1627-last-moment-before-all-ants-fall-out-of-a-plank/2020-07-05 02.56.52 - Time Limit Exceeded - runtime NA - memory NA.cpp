class Solution {
   /* void print(vector<int> &a,vector<int> &b,int n) {
        for (int i = 0;i<=n;++i) {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
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
        while(a[n]+b[0] != ants) {
            time++;
            //printf("\nBefore\n");
            //print(a,b,n);
            for(int i =n-1;i>=0;--i) {
                if (a[i] > 0) {
                   // printf("%d\n",i);
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
            //printf("\nAfter\n");
            //print(a,b,n);
        }
        return time;
    }
};