class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int size = A.size();
        vector<int> result;
        while (size > 0) {
            for(int i = 0;i < size;++i) {
                cout<<"A[i]:"<<A[i]<<endl;
                if (A[i] == size) {
                    cout<<"8888888888888888888"<<endl;
                    result.push_back(i+1);
                    reverse(A.begin(),A.begin()+i+1);
                    result.push_back(size);
                    reverse(A.begin(),A.begin()+size);
                    --size;
                    break;
                }
            }
        }
        return result;
    }
};