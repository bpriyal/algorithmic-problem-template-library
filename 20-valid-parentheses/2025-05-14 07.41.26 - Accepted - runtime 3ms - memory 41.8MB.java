class Solution {
    public boolean isValid(String s) {

        Map<Character,Character> pairs = new HashMap<>();
        pairs.put(')','(');
        pairs.put('}','{');
        pairs.put(']','[');
        Stack<Character> stack = new Stack();

        for (int i = 0; i < s.length(); ++i) {
            char currChar = s.charAt(i);
            if (currChar == '(' || currChar == '{' || currChar == '[') {
                stack.push(Character.valueOf(currChar));
            }
            if (pairs.containsKey(currChar)) {
                if (stack.size() == 0) return false;
                if (!(stack.pop() == pairs.get(currChar))) {
                    return false;
                }
                // else //popped already stack.pop()
            }
        }
        return (stack.size() == 0);
    }
}