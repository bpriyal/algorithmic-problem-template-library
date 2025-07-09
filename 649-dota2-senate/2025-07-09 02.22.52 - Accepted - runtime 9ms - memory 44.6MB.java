class Solution {
    public String predictPartyVictory(String senate) {
        Queue<Character> status = new ArrayDeque();
        if (senate == null || senate.length() == 0) return "";
        int r = 0;
        int totalr = 0;
        int d = 0;
        int totald = 0;
        for (char c : senate.toCharArray()) {
            if (c == 'R') {
                status.add('R');
                totalr++;
            }
            else {
                status.add('D');
                totald++;
            }
        }
        status.add('*');

        while (status.size() > 1) {
            char c = status.poll();
            if (c == 'R') {
                if (d > 0) {
                    d--;
                    totalr--;
                }
                else {
                    r++;
                    status.add('R');
                }
            } else if (c == 'D') {
                if (r > 0) {
                    r--;
                    totald--;
                }
                else {
                    d++;
                    status.add('D');
                }
            } else { //*
                if (totalr == 0 && totald > 0) return "Dire";
                else if (totald == 0 && totalr > 0) return "Radiant";
                status.add('*');
            }
        }
        if (status.size() == 1 && status.poll() == 'R') return "Radiant";
        return "Dire";
    }
}