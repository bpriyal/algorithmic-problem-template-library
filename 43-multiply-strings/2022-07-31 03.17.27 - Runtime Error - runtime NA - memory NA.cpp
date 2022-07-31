class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        
        if(size1 < size2) {
            cout<<"swappping..."<<endl;
            string temp = num1;
            num1 = num2;
            num2 = temp;
            
            int intTemp = size1;
            size1 = size2;
            size2 = intTemp;
        }
        
        int j = 0;
        int result = 0;
        
        while(j < size2) {
            int run = 0;
            int rec = 0;
            int i = 0;
            while(i < size1) {
                int mult = (num1[size1 - i - 1] - '0') * (num2[size2 - j - 1] - '0') + rec;
                cout<<"mult:"<<mult<<endl;
                run += (mult%10)*pow(10,i);
                cout<<"run:"<<run<<endl;
                rec = mult/10;
                cout<<"rec:"<<rec<<endl;
                ++i;
            }
            run = rec*pow(10,i) + run;
            
            result += run*pow(10,j);
            ++j;
        }
        
        return to_string(result);
    }
};