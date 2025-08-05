class Solution {

    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        if (k == 1) return matrix[0][0];
        if (k == n * n) return matrix[n - 1][n - 1];
        return track(matrix, k);
    }

    private int track(int[][] matrix, int k) {
        int n = matrix.length;
        int[] ij1 = new int[]{0, 1};
        int[] ij2 = new int[]{1, 0};
        int count = 2; // already passed matrix[0][0], [0][1], [1][0]
        int lastVal = Math.min(matrix[ij1[0]][ij1[1]], matrix[ij2[0]][ij2[1]]);

        while (count < k) {
            sanity(ij1, n);
            sanity(ij2, n);

            int val1 = getVal(matrix, ij1);
            int val2 = getVal(matrix, ij2);

            if (val2 < val1) {
                lastVal = val2;
                count++;
                ij2 = moveNext(matrix, ij2, n);
            } else {
                lastVal = val1;
                count++;
                ij1 = moveNext(matrix, ij1, n);
            }
        }

        return lastVal;
    }

    private void sanity(int[] ij, int n) {
        if (ij[0] >= n) {
            ij[0] = 0;
            ij[1]++;
        }
        if (ij[1] >= n) {
            ij[1] = 0;
            ij[0]++;
        }
    }

    private int[] moveNext(int[][] matrix, int[] ij, int n) {
        int row = ij[0], col = ij[1];
        boolean downValid = row + 1 < n;
        boolean rightValid = col + 1 < n;

        if (!downValid && !rightValid) return ij;

        if (!downValid) return new int[]{row, col + 1};
        if (!rightValid) return new int[]{row + 1, col};

        if (matrix[row + 1][col] < matrix[row][col + 1]) {
            return new int[]{row + 1, col};
        } else {
            return new int[]{row, col + 1};
        }
    }

    private int getVal(int[][] matrix, int[] ij) {
        int n = matrix.length;
        if (ij[0] < n && ij[1] < n) {
            return matrix[ij[0]][ij[1]];
        }
        return Integer.MAX_VALUE;
    }
}
