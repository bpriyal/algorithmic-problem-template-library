class Solution {
    void sumTwoStrings(string& target, const string& source) {
        cout<<"target: "<<target<<", source: "<<source<<endl;
        int sizeT = target.size() - 1;
        int sizeS = source.size() - 1;
        int carry = 0;

        while (sizeT >=0 && sizeS >= 0) {
            int sum = (target[sizeT] - '0') + (source[sizeS] - '0') + carry;
            carry = sum / 10;
            target[sizeT] = (sum % 10) + '0';
            --sizeT;
            --sizeS;
        }

        while (sizeT >= 0) {
            int sum = (target[sizeT] - '0') + carry;
            carry = sum / 10;
            target[sizeT] = (sum % 10) + '0';
            --sizeT;
        }

        while (sizeS >= 0) {
            int sum = (source[sizeS] - '0') + carry;
            carry = sum / 10;
            cout<<"before target: "<<target<<endl;
            target = to_string((sum % 10))+ target;
            cout<<"after target: "<<target<<endl;
            --sizeS;
        }

        if (carry) target = to_string(carry)+ target;
    }
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int size1 = num1.size();
        int size2 = num2.size();
        string result = "";

        for (int i = size2 - 1; i >= 0; --i) { // second number
            int carry = 0;
            string tempResult = "";
            int multiplicand = num2[i] - '0';

            if (!multiplicand) {
                tempResult = "0";
                sumTwoStrings(result, tempResult);
                continue;
            }

            for (int j = size1 - 1; j >= 0; --j) { // first number
                int multiplier = num1[j] - '0';

                int mult = multiplier * multiplicand + carry;
                tempResult = to_string(mult % 10) + tempResult;
                carry = mult / 10;
            }

            if (carry) tempResult = to_string(carry) + tempResult;

            // append zeroes
            int zeroesToAppend = (size2 - 1) - i;
            while (zeroesToAppend) {
                tempResult += '0';
                --zeroesToAppend;
            }
            //cout<<"After appending zeroes: "<<tempResult<<endl;

            sumTwoStrings(result, tempResult);
            cout<<"After summing: "<<result<<endl;
        }

        return result;
    }
};