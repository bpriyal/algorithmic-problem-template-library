class Solution {
    bool util(vector<int> &position,int l,int h,int balls,int mid) {
        int prev = -1;
        for(int i = l;i<=h;++i) {
            if (prev == -1 || position[i]-position[prev] >= mid) {
                --balls;
                prev = i;
            }
            if (balls == 0) {
                return true;
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int size = position.size();
        sort(position.begin(),position.end());
        int l = 0;
        int h = size - 1;
        int mid;
        while(l <= h) {
            mid = l+(h-l)/2;
            cout<<mid<<endl;
            if (util(position,l,h,m,position[mid])) {
                cout<<"hre"<<endl;
                l = mid+1;
            } else {
                h = mid - 1;
            }
        }
        return position[mid]-1;
    }
};