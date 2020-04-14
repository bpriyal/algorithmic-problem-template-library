class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int i,j;
        string left,right;
        int total_shifts=0;
        for(i=0;i<shift.size();i++){
            total_shifts = total_shifts+ ((shift[i][0]==1) ? shift[i][1] : -shift[i][1]);
        }
        if (total_shifts > 0){
            total_shifts% = s.size();
        } else {
            total_shifts = -((-total_shifts) % s.size());
        }
        if (total_shifts > 0) {
            left = s.substr(0,s.size()-total_shifts);
            right = s.substr(s.size()-total_shifts,total_shifts);
        } else {
            left = s.substr(0,-total_shifts);
            right = s.substr(-total_shifts,s.size()+total_shifts);
        }
        return right+left;
        
    }
};