class Solution {
    public int calculate(String s) {
        char arr[] = s.toCharArray();
        Stack<String> jenga = new Stack();
        StringBuilder sb = new StringBuilder();
        sb.append("0");
        for (int i = 0; i < arr.length; ++i) {
            char c = arr[i];
            if (Character.isDigit(c)) {
                sb.append(c);
            } else if (c == '+' || c == '-' || c == '*' || c == '/'){
                jenga.push(sb.toString());
                sb.setLength(0);
                if (c == '*' || c == '/') {
                    Integer n = 0;
                    Integer a = Integer.parseInt(jenga.pop());
                    Integer b = Integer.parseInt("0");
                    int j = 0;
                    for ( j = i + 1; j < arr.length; ++j) {
                        char c1 = arr[j];
                        if (c1 == ' ') continue;
                        if (Character.isDigit(c1)) {
                            sb.append(c1);
                        } else {
                            b = Integer.parseInt(sb.toString());
                            sb.setLength(0);
                            break;
                        }
                    }
                    i = j - 1;
                    if (sb.length() > 0) b = Integer.parseInt(sb.toString());
                    if (c == '*') {
                        n = a * b;
                    } else if (c == '/' && b != 0) {
                        n = a / b;
                    }
                    jenga.push(n.toString());
                } else if (c == '+' || c == '-') {
                    jenga.push(Character.toString(c));
                }
            } else if (c == ' ') continue;
            else continue;
        } 
        // jenga.reverse();
        while (jenga.size() > 2) {
            int a = Integer.parseInt(jenga.pop());
            String sign = jenga.pop();
            int b = Integer.parseInt(jenga.pop());
            Integer res = Integer.parseInt("0");
            if (sign.equals("+")) {
                res = a + b;
            } else if (sign.equals("-")) {
                res = b - a;
            }
            jenga.push(res.toString());
        }

        return Integer.valueOf(jenga.pop());
    }
}