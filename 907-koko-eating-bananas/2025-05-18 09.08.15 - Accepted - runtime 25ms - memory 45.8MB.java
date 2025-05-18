class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int right = maxPiles(piles);
        return binSearch(piles, 1, right, h);
    }

    int binSearch(int[] piles, int left, int right, int h) {
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (isPossible(piles, h, mid)) right = mid;
        else left = mid + 1;
      }
      return left;
    }

    boolean isPossible(int[] piles, int h, int eatk) {
      int nAtK = 0;
      for (int b : piles) {
        nAtK += Math.ceil((double)b / eatk);
      }
      return nAtK <= h;
    }

    int maxPiles(int[] piles) {
      int max = piles[0];
      for (int i : piles) {
        if (max < i) max = i;
      }
      return max;
    }

    
    
    
    // 3 6 7 11 = 27
    //  3 4 2 4 3 4 4 3


    // 1 1 1 24 = 27

    // noOfPiles < hours
    //     3 5 4 3 3 4 4
    //     h: 5

    // h - piles.length
        

    // noOfPiles = hours
    //     bananas to eat = max(piles)

    // noOfPiles > hours



}