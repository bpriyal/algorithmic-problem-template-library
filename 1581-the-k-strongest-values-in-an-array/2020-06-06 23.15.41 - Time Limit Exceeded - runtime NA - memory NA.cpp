bool compare(const int &a,const int &b,int m) {
        cout<<m<<endl;
        int x = (a-m) > 0? a-m:m-a;
        int y = (b-m) > 0? b-m:m-b;
    cout<<"x:"<<x<<"y:"<<y<<endl;
        return (x > y || (x == y && a > b));
}
class Median {
    int m;
    public:
        Median(int me) :m(me) {}
        bool operator () (const int &a,const int &b) {
            return compare(a,b,m);
        }
};
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int size = arr.size();
        sort(arr.begin(),arr.end());
        int m = arr[(size-1)/2];
        sort(arr.begin(),arr.end(),Median(m));
        return vector<int>(arr.begin(),arr.begin()+k);
        
    }
};