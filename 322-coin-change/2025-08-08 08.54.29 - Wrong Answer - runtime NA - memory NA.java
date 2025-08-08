class Solution {
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        int rem = amount;
        int total = 0; 
        int i = coins.length - 1;
        for ( i = coins.length - 1; i >= 0; --i) {
            int nc = amount / coins[i];
            amount = amount - (nc * coins[i]);
            total += nc;
            if (amount == 0) return total;
        }
        if (amount == 0) return total;
        return -1;
    }
}