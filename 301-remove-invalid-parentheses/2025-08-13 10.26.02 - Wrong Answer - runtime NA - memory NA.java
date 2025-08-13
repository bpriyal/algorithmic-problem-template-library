import java.util.*;

class Solution {
    Set<String> balanced = new HashSet<>();

    public List<String> removeInvalidParentheses(String s) {
        // 1) Count total extra ) and ( in the whole string
        int left = 0, remRight = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left == 0) remRight++;
                else left--;
            }
        }

        // 2) Remove exactly remRight ')' globally
        balanced.clear();
        if (remRight == 0) {
            balanced.add(s);
        } else {
            balAndAddBackTrack(0, s.length() - 1, remRight, new StringBuilder(s));
        }

        // If we never had extra ')', seed with original string for '(' cleanup
        if (balanced.isEmpty()) balanced.add(s);

        // 3) For each candidate, remove its remaining extra '(' (recompute per string)
        Set<String> out = new HashSet<>();
        for (String str : new ArrayList<>(balanced)) {
            int extraLeft = countExtraLeft(str);
            if (extraLeft == 0) {
                if (isValid(str)) out.add(str);
            } else {
                balLeft(0, extraLeft, new StringBuilder(str), str, out);
            }
        }

        // If no '(' needed removal and candidates already valid
        if (out.isEmpty()) out.addAll(balanced);

        return new ArrayList<>(out);
    }

    // remove exactly noOfRight ')' anywhere in [start..end]
    void balAndAddBackTrack(int start, int end, int noOfRight, StringBuilder sb) {
        if (noOfRight == 0) {
            balanced.add(sb.toString());
            return;
        }
        for (int i = start; i <= end; ++i) {
            if (sb.charAt(i) != ')') continue;
            if (i != start && sb.charAt(i) == sb.charAt(i - 1)) continue; // skip dup ')'
            char removed = sb.charAt(i);
            sb.deleteCharAt(i);
            balAndAddBackTrack(i, end - 1, noOfRight - 1, sb);
            sb.insert(i, removed); // always restore
        }
    }

    // remove exactly 'left' '(' starting anywhere (use 0 as start; adjust for length changes)
    void balLeft(int winStart, int left, StringBuilder sb, String par, Set<String> out) {
        if (left == 0) {
            if (isValid(sb.toString())) out.add(sb.toString());
            return;
        }
        int start = Math.max(0, Math.min(winStart, sb.length() == 0 ? 0 : sb.length() - 1));
        for (int i = sb.length() - 1; i >= start; --i) {
            if (sb.charAt(i) != '(') continue;
            if (i < sb.length() - 1 && sb.charAt(i) == sb.charAt(i + 1)) continue; // skip dup '('
            sb.deleteCharAt(i);
            balLeft(i, left - 1, sb, par, out);
            sb.insert(i, '('); // restore
        }
    }

    // extra '(' left after pairing in this string
    int countExtraLeft(String s) {
        int left = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left > 0) left--;
            }
        }
        return left;
    }

    // final sanity check
    boolean isValid(String s) {
        int bal = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') bal++;
            else if (c == ')') {
                if (bal == 0) return false;
                bal--;
            }
        }
        return bal == 0;
    }
}
