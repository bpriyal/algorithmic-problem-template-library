class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        
        // int max = findMax(candies);
        int max = 0;
        for(int val : candies){
            if(val > max){
                max = val;
            }
        }

        // max - i <= extraCandies;
        List<Boolean> result = new ArrayList<>();
        Collections.fill(result, Boolean.FALSE);
        for(int c : candies){
            if(c + extraCandies >= max){
                result.add(Boolean.TRUE);
            }
            else{
                result.add(Boolean.FALSE);
            }
        }
        return result;       
    }
}