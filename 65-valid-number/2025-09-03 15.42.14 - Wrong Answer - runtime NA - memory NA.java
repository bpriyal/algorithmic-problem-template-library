class Solution {
    public boolean isNumber(String s) {
        if (s.indexOf("e") != s.lastIndexOf("e")) return false;
        if (s.indexOf("E") != s.lastIndexOf("E")) return false;
        if (s.indexOf("e") != -1 && s.indexOf("E") != -1) return false;
        String[] splits = s.split("[eE]");
        if (s.indexOf("e") != -1 || s.indexOf("E") != -1) if (splits.length != 2) return false;
        if(splits.length > 2 || splits.length < 1) return false;
        if (splits[0].length() == 0) return false;
        if (splits.length == 2 && splits[1].length() == 0) return false;
        boolean ans0 = false;
        if (s.indexOf(".") == -1) 
            ans0 = checkInt(splits[0]);
        else ans0 = checkDeci(splits[0]);
        if (splits.length == 1) return ans0;
        return ans0 && checkInt(splits[1]);
    }

    boolean checkInt (String s) {
        int startInd = 0;
        if (s.charAt(0) == '+' || s.charAt(0) == '-') {
            startInd = 1;
        }
        for (int i = startInd; i < s.length(); ++i) {
            if (!Character.isDigit(s.charAt(i))) return false;
        }
        return true;
    }

    boolean checkDeci(String s) {
        if (s.indexOf(".") != s.lastIndexOf(".")) return false;
        String splits[] = s.split("[.]");
        if (splits.length == 2) {
            if(!Character.isDigit(splits[1].charAt(0))) return false;
            if (splits[0].length() == 0) return checkInt(splits[1]);
            return checkInt(splits[0]) && checkInt(splits[1]);
        }
        if (splits.length == 1) {
            if(!Character.isDigit(splits[0].charAt(0))) return false;
            return checkInt(splits[0]);
        }
        return false;
    }
}