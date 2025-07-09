class Solution {
    public String predictPartyVictory(String senate) {
        Queue<Character> status = new ArrayDeque();
        if (senate == null || senate.length() == 0) return "";
        for (char c : senate.toCharArray()) status.add(c);
        status.add('*');
        int r = 0;
        int d = 0;
        while (status.size() > 1) {
            char c = status.poll();
            if (c == 'R') {
                if (d > 0) d--;
                else {
                    r++;
                    status.add('R');
                }
            } else if (c == 'D') {
                if (r > 0) r--;
                else {
                    d++;
                    status.add('D');
                }
            } else { //*
                if (r == 0 && d > 0) return "Dire";
                else if (d == 0 && r > 0) return "Radiant";
            }
        }
        if (status.size() == 1 && status.poll() == 'R') return "Radiant";
        return "Dire";
    }
}