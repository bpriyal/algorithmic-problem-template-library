class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int minDigits = 0;
        int maxDigits = 0;
        int temp = low;
        while(temp) {
            ++minDigits;
            temp /= 10;
        }
        temp = high;
        while(temp) {
            ++maxDigits;
            temp /= 10;
        }
        vector<int> result;
        
        for(int nbDigit = minDigits;nbDigit <= maxDigits;++nbDigit) {
            for(int d=1;d<=9;++d) {
                int temp = nbDigit;
                int number = 0;
                int currD = d;
                while(temp > 0) {
                    if (temp != 1 && currD==9) {
                        number = INT_MAX;
                        break;
                    }
                    number = number*10 + currD;
                    ++currD;
                    --temp;
                }
                if (number > high) {
                    break;
                }
                if (number >= low && number <=high) {
                    result.push_back(number);
                }
            }
        }
        
        return result;
    }
};