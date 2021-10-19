import java.util.*;

class SpiralMatrix{

	// Function to print in spiral order
	public static List<Integer> spiralOrder(int[][] matrix)
	{
		List<Integer> ans = new ArrayList<Integer>();

		if (matrix.length == 0)
			return ans;

		int R = matrix.length, C = matrix[0].length;
		boolean[][] seen = new boolean[R][C];
		int[] dr = { 0, 1, 0, -1 };
		int[] dc = { 1, 0, -1, 0 };
		int r = 0, c = 0, di = 0;

		// Iterate from 0 to R * C - 1
		for (int i = 0; i < R * C; i++) {
			ans.add(matrix[r]);
			seen[r] = true;
			int cr = r + dr[di];
			int cc = c + dc[di];

			if (0 <= cr && cr < R && 0 <= cc && cc < C
				&& !seen[cr][cc]) {
				r = cr;
				c = cc;
			}
			else {
				di = (di + 1) % 4;
				r += dr[di];
				c += dc[di];
			}
		}
		return ans;
	}

	// Driver Code
	public static void main(String[] args)
	{
		int a[][] = { { 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 } };

		System.out.println(spiralOrder(a));
	}
}
