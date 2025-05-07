class Solution {
    public String longestCommonPrefix(String[] strs) {
        List<String> listStrs = new ArrayList<>(Arrays.asList(strs));
        Collections.sort(listStrs);
        // System.out.println(listStrs);
        
        return commonPrefix(listStrs.get(0), listStrs.get(listStrs.size() - 1));
        
    }

    String commonPrefix(String word1, String word2) {
        //find min length out of 2 words
        //check character by character and 
        int min = Math.min(word1.length(), word2.length());
        int i = 0;
        while (i < min && word1.charAt(i) == word2.charAt(i)) {
            i++;
        }
        return word1.substring(0,i);
    }

}