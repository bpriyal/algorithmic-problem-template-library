class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n+1);
        vector<int> numbers;
        fact[0] = 1;
        for(int i=1;i<=n;i++) {
            fact[i] = fact[i-1]*i;
        }
        for(int i = 0;i<n;++i) {
            numbers.push_back(i+1);
        }
        string result = "";
        int i = 1;
        while(k != 0) {
            double temp = (double)k/fact[n-i];
            int c = ceil(temp);
            cout<<"here:"<<c<<endl;
            result += to_string(numbers[c-1]);
            numbers.erase(numbers.begin()+c-1);
            cout<<"hre1"<<endl;
            k = k%fact[n-i];
            ++i;
        }
        for(int i = numbers.size()-1;i>=0;--i) {
            result += to_string(numbers[i]);
        }
        
        return result;
    }
};