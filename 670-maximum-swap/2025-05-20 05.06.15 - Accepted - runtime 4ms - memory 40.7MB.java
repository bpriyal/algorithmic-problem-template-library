class Solution {
    public int maximumSwap(int num) {
        // String numStr = Integer.toString(num);
        // int n = numStr.length();
        // char[] numeral = numStr.toCharArray();

        // numeral
        List < Integer > digits = new ArrayList();
        List < Integer > sortedDigits = new ArrayList();

        String stringN = Integer.toString(num);
        for (int i = 0; i < stringN.length(); i++) {
            // convert the charAt(i) to integer here?
            digits.add(i, stringN.charAt(i) - '0');
        } 

        for (int i = 0; i < stringN.length(); i++) {
            // convert the charAt(i) to integer here?
            sortedDigits.add(i, stringN.charAt(i) - '0');
        }        

        Collections.sort(sortedDigits, Collections.reverseOrder());
        
        for (int i = 0; i < sortedDigits.size(); ++i) {
            int swap;
            if(sortedDigits.get(i) != digits.get(i)) {
                swap = digits.get(i); //3
                digits.remove(i);
                digits.add(i, sortedDigits.get(i)); //9
                
                for (int j = digits.size() - 1; j >= 0; --j) {
                    if (digits.get(j) == digits.get(i)) {
                        digits.remove(j);
                        digits.add(j, swap);
                        break;
                    }
                }   
                break;    
            }
        }
        System.out.println(digits.toString()); 
        int n = digits.get(0);
        for (int i = 1; i < digits.size(); ++i) {
            n = n * 10;
            n += digits.get(i);
        }
        return n;
    }
}

// 375829592
// 987559232

// max
// 9758235

// 9798235
// max
// 9978235