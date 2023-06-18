class Solution {
    public String removeStars(String s) {
        StringBuilder newS = new StringBuilder();
        for (int i = 0; i < s.length(); ++i){
            char c = s.charAt(i);
            if (c != '*'){
                System.out.println(c);
                newS.append(c);
            }
            else { //when * encountered
                // if(i > 0 && s.charAt(i-1) != '*'){
                    System.out.println(i);
                    // System.out.println(newS.charAt(i));
                    newS.deleteCharAt(newS.length() - 1);
                // }
            }
        }
        return newS.toString();
    }
}