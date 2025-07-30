class Solution {
    public String addStrings(String num1, String num2) {
        int i1 = num1.length() - 1;
        int i2 = num2.length() - 1;
        int carry = 0;
        StringBuilder number = new StringBuilder();
        while (i1 >= 0 || i2 >= 0) {
            StringBuilder temp = new StringBuilder();
            int a = i1 >= 0 ? num1.charAt(i1) - '0' : 0;
            int b = i2 >= 0 ? num2.charAt(i2) - '0' : 0;
            int val = (a + b + carry) % 10;
            carry =  (a + b + carry) / 10;
            number = temp.append(val).append(number);
            i1--; i2--;
        }
        StringBuilder temp = new StringBuilder();
        number = carry > 0 ? temp.append(carry).append(number) : number;
        return number.toString();
    }
}