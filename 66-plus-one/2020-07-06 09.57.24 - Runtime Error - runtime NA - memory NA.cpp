class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        vector<int> result;
        int number = digits[0];
        for(int i = 1;i < size;++i) {
            number = number * 10 + digits[i];
        }
        ++number;
        while(number != 0) {
            result.insert(result.begin(),number%10);
            number /= 10;
        }
        return result;
    }
};