class Solution {
    public int maxVowels(String s, int k) {
        
        int len = s.length();
        int arr[] = new int[len];
        int sum = 0;
        for(int i = 0; i < len; ++i){
            int val = isVowel(s.charAt(i));  
            arr[i] = val;
            if(i < k){
                sum += val;
            }
        }

        int max = sum;
        for(int i = k; i < len; ++i){
            sum += arr[i] - arr[i-k];
            if(max < sum){
                max = sum;
            }
        }

        return max;

    }

    int isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return 1;
        }
        return 0;
    }
}