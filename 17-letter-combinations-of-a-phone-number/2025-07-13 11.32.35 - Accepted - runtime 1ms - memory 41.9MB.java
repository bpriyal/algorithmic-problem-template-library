class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits == null || digits.length() == 0) return new ArrayList();
        Map<Integer, List<Character>> phoneMap = new HashMap();
        char c = 'a' - 1;
        for (int i = 2; i < 10; ++i) {
            if (i == 7 || i == 9) phoneMap.put(i, new ArrayList<Character>(Arrays.asList(++c, ++c, ++c, ++c)));
            else phoneMap.put(i, new ArrayList<Character>(Arrays.asList(++c, ++c, ++c)));
        }
        List<String> result = new ArrayList<>();
        dfs(digits, 0, new StringBuilder(), phoneMap, result);
        return result;
    }

    void dfs(String digits, int index, StringBuilder path,
             Map<Integer, List<Character>> phoneMap, List<String> result) {

        if (index == digits.length()) {
            result.add(path.toString());
            return;
        }

        int digit = digits.charAt(index) - '0';
        List<Character> letters = phoneMap.get(digit);
        if (letters == null) return;

        for (char ch : letters) {
            path.append(ch);
            dfs(digits, index + 1, path, phoneMap, result);
            path.deleteCharAt(path.length() - 1); // backtrack
        }
    }
}
