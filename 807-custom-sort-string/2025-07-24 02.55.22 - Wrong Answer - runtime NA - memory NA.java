class Solution {
    public String customSortString(String order, String s) {
        StringBuilder sb = new StringBuilder(s);

        int early = 0;
        int later = order.length() - 1;
        char earlyPivot = order.charAt(early);
        char laterPivot = order.charAt(later);

        while (early < order.length() - 2) {
            while (early < later) {
                int loe = sb.lastIndexOf(String.valueOf(earlyPivot));
                int eol = sb.indexOf(String.valueOf(laterPivot));
                if (loe == -1) {
                    early++;
                    earlyPivot = order.charAt(early);
                    continue;
                }
                if (eol == -1) {
                    later--;
                    laterPivot = order.charAt(later);
                    continue;
                }

                if (loe < eol) {
                   later--;
                   laterPivot = order.charAt(later);
                }
                else {
                    swap(sb,loe,eol);
                }
            }
            early++;
            earlyPivot = order.charAt(early);
            later = order.length() - 1;
            laterPivot = order.charAt(later);
        }
        return sb.toString();
    }

        void swap(StringBuilder sb, int l, int e) {
            char temp = sb.charAt(l);
            sb.setCharAt(l, sb.charAt(e));
            sb.setCharAt(e, temp);
        }

}

// s = atdijferisdf

// order = rtsagfi

// sb = adijferisdf





