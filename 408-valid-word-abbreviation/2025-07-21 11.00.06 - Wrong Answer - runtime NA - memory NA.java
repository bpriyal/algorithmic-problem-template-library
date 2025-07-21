class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        // Character[] wordarr = new Character[word.length()](word.toCharArray());
        // Character[] abbarr = new Character[abbr.length()];
        int a = 0;
        int num = 0;
        int w = 0;
        for ( w = 0; w < word.length() && a < abbr.length();) {
            if (Character.isLetter(abbr.charAt(a))) {
                if (num != 0) {
                     w += num/10;
                     System.out.println(word.charAt(w));
                     num = 0;
                     continue;
                }
                if (abbr.charAt(a) != word.charAt(w)) return false;
                else {
                    ++a;
                    ++w;
                    continue;
                }
            }
            if (num == 0 && Character.getNumericValue(abbr.charAt(a)) == 0) return false; 
            num += Character.getNumericValue(abbr.charAt(a));
            num *= 10;
            ++a;
            // ++w;
        }
        return (w == word.length() || num != 0);
    }
}