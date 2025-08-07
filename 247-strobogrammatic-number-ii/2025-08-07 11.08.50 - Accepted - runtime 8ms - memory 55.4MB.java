class Solution {
    List<String> result = new ArrayList();
    Set<Character> single = new HashSet();
    Map<Character, Character> doublePair = new HashMap();

    public List<String> findStrobogrammatic(int n) {
        single.add('0');
        single.add('1');
        single.add('8');
        doublePair.put('6', '9');
        doublePair.put('9', '6');
        doublePair.put('1', '1');
        doublePair.put('8', '8');
        doublePair.put('0', '0');
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) sb.append(' ');
        backtrack (sb, 0, n - 1);
        return result;
    }

    void backtrack (StringBuilder sb, int i, int j) {
        if (i > j) {
            return;
        }
        if (i == j) {
            for (char sin : single) {
                sb.setCharAt(i , sin);
                result.add(sb.toString());
            }//set a single
            return;
        }

            for (char key : doublePair.keySet()) {
                if (i == 0 && key == '0') continue;
                if (i > j + 1) break;
                sb.setCharAt(i, key);
                sb.setCharAt(j, doublePair.get(key));
                if (i == j - 1) {
                    result.add(sb.toString());
                    continue;
                }
                backtrack (sb, i + 1, j - 1);
            }  

        
    }
}