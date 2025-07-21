class Solution {
    public String simplifyPath(String path) {
        Stack<String> dirs = new Stack();
        StringBuilder curr = new StringBuilder();
        char[] carr = path.toCharArray();

        for (int c = 0, j = 0; c < path.length();) {
            if (carr[c] == '.') {
                while (j < carr.length && carr[j] == '.') {
                    curr.append(carr[j++]);
                }
                int dotsLen = curr.length();
                if (dotsLen == 2) {
                    if (dirs.size() > 0) 
                        dirs.pop();
                } else if (dotsLen > 2) {
                    dirs.push(curr.toString());
                }
                c = j;
                curr = new StringBuilder();
            } else if (carr[c] == '/') {
                if (curr.length() > 0) dirs.push(curr.toString());
                curr = new StringBuilder();
                while (j < carr.length && carr[j] == '/') {
                    j++;
                }
                c = j;
            } else {
                curr.append(carr[c]);
                c++; j++;
            }
        }
        if (curr.length() > 0) dirs.push(curr.toString());
        if (dirs.size() == 0) return "/";
        curr = new StringBuilder();
        curr.append('/').append(dirs.pop());
        while (!dirs.isEmpty()) {
            StringBuilder temp = new StringBuilder();
            temp.append('/').append(dirs.pop()).append(curr);
            curr = temp;
        }
        return curr.toString();
    }
}