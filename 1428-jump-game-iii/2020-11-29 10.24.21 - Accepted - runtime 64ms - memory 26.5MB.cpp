class Solution {
    int size;
    bool util(vector<int> &arr,int pos) {
       // cout<<pos<<endl;
        if (pos < 0 || pos >= size || arr[pos] == -1) {
            return false;
        }
       // cout<<"arr:"<<arr[pos]<<endl;
        if (arr[pos] == 0) {
            return true;
        }
        int temp = arr[pos];
        arr[pos] = -1;
        bool ret = util(arr,pos-temp) || util(arr,pos+temp);
        arr[pos] = temp;
        return ret;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        size = arr.size();
        return util(arr,start);
    }
};