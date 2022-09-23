class Solution {
    string getBinary(int n) {
        string s = "";
        
        while (n) {
            s = to_string(n % 2) + s;
            n /= 2;
        }
        
        return s;
    }
    
    constexpr long int modulo() { return pow(10, 9) + 7; }
public:
    int concatenatedBinary(int n) {
        string binaryString = "";
        
        for (int i = 1; i <= n; ++i) binaryString += getBinary(i);
        
        // cout<<binaryString<<endl;
        
        int result = 0;
        int mult = 1;
        for (auto it = binaryString.rbegin(); it != binaryString.rend(); ++it) {
            result = (result + ((*it - '0') * mult) % modulo()) % modulo();
            mult = (mult * 2) % modulo();
            // cout<<result<<endl;
        }
        
        return result;
    }
};