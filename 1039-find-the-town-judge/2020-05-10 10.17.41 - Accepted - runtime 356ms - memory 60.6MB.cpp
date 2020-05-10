class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<bool> arr(N,false);
        for(auto &x:trust) {
            arr[x[0]-1] = true;
        }
        int count = 0;
        int ele = -1;
        cout<<"arr:"<<arr[0]<<","<<arr[1]<<","<<arr[2]<<endl;
        for(int i =0;i<N;++i) {
            if (count>1) return -1;
            if (arr[i] == false) {
                ++count;
                ele = i+1;
            }
        }
        cout<<ele<<endl;
        vector<bool> arr1(N,false);
        if (ele == -1) return -1;
        for(auto &x : trust) {
            if (x[1] == ele) {
                arr1[x[0]-1] = true;
            }
        }
        for(int i =0;i<N;++i) {
            if (i == ele -1) continue;
            if (arr1[i] == false) return -1;
        }
        return ele;
    }
};