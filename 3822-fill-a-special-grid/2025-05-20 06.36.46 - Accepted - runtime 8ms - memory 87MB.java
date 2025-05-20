class Solution {
    int VAL = 0;
    public int[][] specialGrid(int n) {
        int size = 1 << n;
        int[][] grid = new int[size][size];
        spiral(grid, 0, 0, size);
        return grid;
    }
    void spiral (int[][] grid, int r, int c, int size) {
        if (size == 1) {
            grid[r][c] = VAL++;
            return;
        }
        int s = size / 2;
        spiral (grid, r, c + s, s);
        spiral (grid, r + s, c + s, s);
        spiral (grid, r + s, c, s);
        spiral (grid, r, c, s);
    }
}

// _ _
// _ _

// 00 01
// 10 11

// 3 0
// 2 1

// _ _ _ _
// _ _ _ _
// _ _ _ _
// _ _ _ _
// 00 01 02 03
// 10 11 12 13
// 20 21 22 23
// 30 31 32 33

// 00 01 00 01
// 10 11 10 11

// 15 12 3 0
// 14 13 2 1
// 11  8 7 4
// 10  9 6 5

//                 15 12 3 0
//                 14 13 2 1
//                 11  8 7 4
//                 10  9 6 5
//                       19 16
//                       18 17
                      