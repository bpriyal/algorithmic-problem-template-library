class Solution {
    bool util(vector<int> &position,int balls,int mid) {
        int prev = -1;
        for(int i = 0;i<position.size();++i) {
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
        if(m == 2) {
            return position[size-1]-position[0];
        }
        int l = 1;
        int h = (position[size-1]-position[0]);
        int mid,result;
        while(l <= h) {
            mid = l+(h-l)/2;
            //cout<<mid<<endl;
            if (util(position,m,mid)) {
                //cout<<"hre"<<endl;
                result = mid;
                l = mid+1;
            } else {
                h = mid-1;
            }
        }
        return result;
    }
};