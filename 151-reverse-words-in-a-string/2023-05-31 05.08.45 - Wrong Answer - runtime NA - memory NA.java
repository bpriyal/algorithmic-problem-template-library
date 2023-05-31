class Solution {
    public String reverseWords(String s) {
        
        StringBuilder reverse = new StringBuilder();

        s = s.trim();
        int sLen = s.length(); 

        int start = -1;
        int end = sLen;
        for(int i =  sLen - 1; i >= 0; --i){
            if(s.charAt(i) == ' ' || i == 0){
                while(i-1 > 0 && s.charAt(i-1) == ' '){
                    --i;
                }
                start = i+1;
                if(i == 0){
                    start = 0;
                }
                reverse.append(s.substring(start,end));
                reverse.append(" ");
                end = i;
            }    
        }

        return reverse.toString().trim();
    }
}