class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int carry = 0;
        vector<int> result;
        for (int i = size - 1; i >= 0; --i) {
            int temp = digits[i] + carry + ((i == size - 1)? 1 : 0);
            result.push_back(temp % 10);
            carry = temp / 10;
            //if (!carry) break;
        }

        if (carry) result.push_back(carry);

        reverse(result.begin(), result.end());

        return result; 
    }
};