class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int units = 0;
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[1] > v2[1];
        });

        for (auto box : boxTypes) {
            cout<<box[0]<<endl;
            int maxAllowed = min(box[0], truckSize);
            if (!maxAllowed) break;
            truckSize -= maxAllowed;
            units += maxAllowed * box[1];
        }

        return units;
    }
};