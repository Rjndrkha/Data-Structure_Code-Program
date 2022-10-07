// You are given an m x n integer matrix grid.

// We define an hourglass as a part of the matrix with the following form:

// Return the maximum sum of the elements of an hourglass.

// Note that an hourglass cannot be rotated and must be entirely contained within the matrix.
class Solution {

    public int maxSum(int[][] grid) {
        int result = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i + 2 < m && j + 2 < n) {
                    int sum = 0;
                    sum += grid[i][j];
                    sum += grid[i][j + 1];
                    sum += grid[i][j + 2];
                    sum += grid[i + 1][j + 1];
                    sum += grid[i + 2][j];
                    sum += grid[i + 2][j + 1];
                    sum += grid[i + 2][j + 2];
                    result = Integer.max(result, sum);
                }
            }
        }
        return result;
    }
}
