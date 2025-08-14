class Solution {
    public void rotate(int[][] matrix) {
        for (int dia = matrix.length; dia > 0; dia -= 2) {
            flipOuterCircle (matrix, dia);
        }
    }
    void flipOuterCircle (int[][] matrix, int dia) {
    int n = matrix.length;
    int start = (n - dia) / 2;
    int a = start;
    int b = start + dia -1;

    for (int j = 0; j < dia - 1; ++j) {
        // int n1 = matrix[a][a + j];
        // int n2 = matrix[a + j][b];
        // int n3 = matrix[b][b - j];
        // int n4 = matrix[b - j][a];
        int temp1 = matrix[a][a + j];
        int temp2 = matrix[a + j][b];
        matrix[a][a + j] = matrix[b - j][a];
        matrix[a + j][b] = temp1;
        temp1 = matrix[b][b - j];
        matrix[b][b - j] = temp2;
        matrix[b - j][a] = temp1;

        // int n1 = matrix[a + j][a ];
        // int n2 = matrix[a + j][b];
        // int n3 = matrix[b][b - j];
        // int n4 = matrix[b - j][a];
    }

}
}


