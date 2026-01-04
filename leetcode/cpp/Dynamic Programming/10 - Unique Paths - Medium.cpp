// DP solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        //    28   21  15  10  6   3   1
        //     7   6   5   4   3   2   1
        //     1   1   1   1   1   1   1
        //
        // The idea here is t simply iterate through
        // the diagonals of the matrix from right to left.

        if (m == 1 || n == 1)
            return 1;

        int dp[100][100];
        int m_last = m - 1;
        int n_last = n - 1;

        // Seed the initial value.
        dp[m_last][n_last] = 1;

        int i = m_last;
        int j = n_last - 1;
        int i_diag_start = i;
        int j_diag_start = j;

        while (i > 0 || j > 0)
        {
            dp[i][j] = 0;

            if (i < m_last)
                dp[i][j] += dp[i + 1][j];
            
            if (j < n_last)
                dp[i][j] += dp[i][j + 1];
            
            if (i == 0 || j == n_last)
            {
                if (j_diag_start > 0)
                    --j_diag_start;
                else if (i_diag_start > 0)
                    --i_diag_start;
                
                i = i_diag_start;
                j = j_diag_start;
            }
            else
            {
                --i;
                ++j;
            }
        }

        return dp[0][1] + dp[1][0];
    }
};