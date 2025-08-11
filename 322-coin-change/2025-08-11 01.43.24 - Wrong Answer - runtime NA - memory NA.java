class Solution {
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        if (amount == 0) return 0;
        return count (coins.length - 1, coins, amount, 0);
    }
    int count (int ind, int[] coins, int remAmount, int total) {
        int i = ind;
    for (; i >= 0; --i) {
        int noOfCoins = remAmount / coins[i];
        int amt = remAmount - noOfCoins * coins[i];
        if (amt == 0) return (total + noOfCoins);
        int j = 1;
        while (i - j < coins.length) {
            int c = count (i - j, coins, amt, total + noOfCoins);
            return c;
        }
    }
    if (i == -1) {
        if (remAmount != 0) {
            int c = count (ind - 1, coins, remAmount, total);
            return c;
        }
        else return total;
    }
        if (i < -1) return -1;
        return -1;
    }
}

//[186,419,83,408]
//6249