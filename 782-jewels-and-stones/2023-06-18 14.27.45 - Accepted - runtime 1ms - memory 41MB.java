class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        Map<Character,Integer> stoneToFreq = new HashMap<>();
        int count = 0;
        for (char c : stones.toCharArray()) {
            stoneToFreq.put (c, stoneToFreq.getOrDefault(c,0) + 1);
        }
        for (char c : jewels.toCharArray()) {
            count += stoneToFreq.getOrDefault (c,0);
        }
        return count;
    }
}