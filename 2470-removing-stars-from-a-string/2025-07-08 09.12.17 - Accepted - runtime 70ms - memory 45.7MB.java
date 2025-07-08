class Solution {
    public String removeStars(String s) {
        Stack<Character> res = new Stack();
        for (char c : s.toCharArray()) {
            if (c != '*') {
                res.push(c);
            } else if (!res.empty()){
                res.pop();
            }
        }
        if (res.size() == 0) return "";
        StringBuilder sb = new StringBuilder();
        for (char c : res) {
            sb.append(c);
        }
        // sb.reverse();
        return sb.toString();
    }
}