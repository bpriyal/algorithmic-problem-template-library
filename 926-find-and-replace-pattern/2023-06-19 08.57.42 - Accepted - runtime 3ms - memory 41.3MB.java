class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> result = new ArrayList();

        for (String w : words) {
            Map<Character,Character> wcToPc = new HashMap<>();
            int i = 0;
            for(; i < pattern.length(); ++i) {
                char c = w.charAt(i);
                if (wcToPc.containsKey(c)) {
                    if(!(wcToPc.get(c) == pattern.charAt(i))){
                        break;
                    }
                }
                else{       
                    if(!wcToPc.values().contains(pattern.charAt(i))){
                        wcToPc.put(c, pattern.charAt(i));
                    }
                    else{
                        break;
                    }      
                }
            }
            if(i == pattern.length()){
                result.add(w);
            }
        }
        return result;
    }
}