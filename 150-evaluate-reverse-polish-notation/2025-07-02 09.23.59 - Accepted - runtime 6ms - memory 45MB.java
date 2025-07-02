class Solution {
    public int evalRPN(String[] tokens) {
        Set<String> ops = new HashSet();
        ops.add("+");
        ops.add("-");
        ops.add("*");
        ops.add("/");

        Stack<Integer> vals = new Stack();

        for (String token : tokens) {
            if (ops.contains(token)) {
                int n1 = vals.pop();
                int n2 = vals.pop();

                if ( token.equals("+") ) {
                    vals.push(n1+n2);
                } else if ( token.equals("-") ) {
                    vals.push(n2-n1);
                } else if ( token.equals("*") ) {
                    vals.push(n1*n2);
                } else if ( token.equals("/")) {
                    vals.push(n2/n1);
                }
            } else {
                vals.push(Integer.parseInt(token));
            }
        }

        return vals.pop();
    }
}