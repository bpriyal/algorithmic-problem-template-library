class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        sort(arrays.begin(), arrays.end(), [](const auto& array1, const auto& array2) {
            if (array1[0] < array1[0]) return true;
            else if (array1[0] > array2[0]) return false;
            else return array1.back() >= array2.back();
        });
        cout<<arrays[0].front()<<endl;
        int min_ = std::numeric_limits<int>::max();
        int max_ = std::numeric_limits<int>::min();

        for (int i = 1; i < m; ++i) {
            min_ = min(min_, arrays[i].front());
            max_ = max(max_, arrays[i].back());
        }
        cout<<"min_: "<<min_<<", max_: "<<max_<<endl;
        return max(abs(arrays[0].front() - max_), abs(arrays[0].back() - min_));
    }
};