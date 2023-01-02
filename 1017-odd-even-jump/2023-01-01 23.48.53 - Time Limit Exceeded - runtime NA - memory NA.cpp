class Solution {
    int size;
    int smallestValGreaterThan(vector<int>& arr, int startIndex, int comp) {
        pair<int, int> indexToVal = { -1, INT_MAX };

        for (int i = startIndex; i < size; ++i) {
            if (comp <= arr[i] && indexToVal.second > arr[i]) {
                indexToVal = { i, arr[i] };
            }
        }

        return indexToVal.second == INT_MAX? -1 : indexToVal.first;
    }

    int largestValSmallerThan(vector<int>& arr, int startIndex, int comp) {
        pair<int, int> indexToVal = { -1, INT_MIN };

        for (int i = startIndex; i < size; ++i) {
            if (comp >= arr[i] && indexToVal.second < arr[i]) {
                indexToVal = { i, arr[i] };
            }
        }

        return indexToVal.second == INT_MIN? -1 : indexToVal.first;
    }
public:
    int oddEvenJumps(vector<int>& arr) {
        size = arr.size();
        int validIndices = 0;

        for (int i = 0; i < size; ++i) {
            int pos = i;
            bool isOddJump = true;
            while (pos < size - 1) {
                int potentialPos;
                if (isOddJump) {
                    potentialPos = smallestValGreaterThan(arr, pos + 1, arr[pos]);
                    //cout<<"odd jump: i - "<<i<<", potentialPos - "<<potentialPos<<endl;
                } else {
                    potentialPos = largestValSmallerThan(arr, pos + 1, arr[pos]);
                    //cout<<"even jump: i - "<<i<<", potentialPos - "<<potentialPos<<endl;
                }
                isOddJump = !isOddJump;
                if (potentialPos == -1) break;
                pos = potentialPos;
                if (pos == size - 1) {
                    ++validIndices;
                    //cout<<i<<endl;
                }
            }
        }

        return validIndices + 1;
    }
};