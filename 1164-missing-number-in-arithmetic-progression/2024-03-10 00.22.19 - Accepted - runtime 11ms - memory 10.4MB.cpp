class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int difference = (arr.back() - arr.front()) /n;
        cout<<(arr.back() - arr.front())/arr.size()<<endl;
        cout<<arr.size()<<endl;
        int expected = arr.front();
        for (const auto& element : arr) {
            cout<<"difference: "<<difference<<", element: "<<element<<endl;
            if (element != expected) return expected;
            expected += difference;
        }
        return expected;
    }
};