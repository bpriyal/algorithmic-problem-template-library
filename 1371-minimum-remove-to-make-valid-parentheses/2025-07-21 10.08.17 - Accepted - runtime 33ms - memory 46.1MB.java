class Solution {
    public String minRemoveToMakeValid(String s) {
        char[] arr = s.toCharArray();
        Set<Integer> removeInds = new TreeSet();
        Stack<Integer> jenga = new Stack();
        int left = 0;
        int right = 0;
        int i = 0;

        for (char c : arr) {
            if (c == '(') {
                left++;
                jenga.push(i);
            } else if (c == ')') {
                if(left == 0) removeInds.add(i);
                else {
                    jenga.pop();
                    left--;
                }
            }
            i++;
        }
        removeInds.addAll(jenga);
        StringBuilder sb = new StringBuilder();
        for ( i = 0; i < arr.length; ++i) {
            if (!removeInds.contains(i))
                sb.append(arr[i]);
        }

        return sb.toString();
        
    }
}