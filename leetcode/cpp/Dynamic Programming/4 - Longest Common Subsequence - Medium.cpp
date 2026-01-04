// Bottom-up Tabularized DP Solution
class Solution {
private:
    int memo[1001][1001];

public:
    int longestCommonSubsequence(string text1, string text2) {
        // If either of the strings has length of 0 then
        // there exists no common subsequence betweeen them.
        if (text1.size() == 0 || text2.size() == 0)
            return 0;

        // Initialize the last row (one past text1 length) and the
        // last column (one past text2 length) to be all 0's for
        // ease of implementation.
        int text1_size = text1.size();
        int text2_size = text2.size();

        // Fill the additonal row with 0's
        for (int i = 0; i <= text2_size; ++i)
            memo[text1_size][i] = 0;

        // Fill the additional col with 0's.
        // No need to modify last row in the last col as it has already been set above.
        for (int i = 0; i < text1_size; ++i)
            memo[i][text2_size] = 0;
        
        // Iterate cols down-up and then rows right to left.
        for (int i = text2_size - 1; i >= 0; --i)
        {
            for (int j = text1_size - 1; j >= 0; --j)
            {
                // Are the two characters equal?
                if (text1[j] == text2[i])
                    memo[j][i] = 1 + memo[j + 1][i + 1];
                else
                    memo[j][i] = max(memo[j + 1][i], memo[j][i + 1]);
            }
        }

        return memo[0][0];
    }
};



// Improved Memoized DP Solution
class Solution {
private:
    int memo[1001][1001];
    string text1, text2;

    int lcs(int p1, int p2)
    {
        if (text1[p1] == '\0' || text2[p2] == '\0')
            return 0;
        
        // Do we already have the answer to this subproblem?
        if (memo[p1][p2] != -1)
            return memo[p1][p2];
        
        if (text1[p1] == text2[p2])
            memo[p1][p2] = 1 + lcs(p1 + 1, p2 + 1);
        else
            memo[p1][p2] = max(lcs(p1 + 1, p2), lcs(p1, p2 + 1));

        return memo[p1][p2];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        // If either of the strings has length of 0 then
        // there exists no common subsequence betweeen them.
        if (text1.size() == 0 || text2.size() == 0)
            return 0;

        // Initialize the memo table to be all -1's to indicate
        // that the memos have not been filled out.
        for (int i = 0; i < 1001; ++i)
            for (int j = 0; j < 1001; ++j)
                memo[i][j] = -1;

        this->text1 = text1;
        this->text2 = text2;

        return lcs(0, 0);
    }
};



// Basic Memoized DP Solution
class Solution {
private:
    int memo[1001][1001];
    string text1, text2;

    int lcs(int p1, int p2)
    {
        if (text1[p1] == '\0' || text2[p2] == '\0')
            return 0;
        
        // Do we already have the answer to this subproblem?
        if (memo[p1][p2] != -1)
            return memo[p1][p2];
        
        // Not part of optimal solution.
        int not_part_of_optimal = lcs(p1 + 1, p2);

        // Is part of optimal solution.
        int first_occurence = 0;
        int part_of_optimal = 0;

        while (text2[p2 + first_occurence] != text1[p1] && text2[p2 + first_occurence] != '\0')
            ++first_occurence;

        if (text2[p2 + first_occurence] != '\0')
            part_of_optimal = 1 + lcs(p1 + 1, p2 + first_occurence + 1);

        // Memoize the solution to this subproblem for future use.
        memo[p1][p2] = max(not_part_of_optimal, part_of_optimal);

        return memo[p1][p2];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        // If either of the strings has length of 0 then
        // there exists no common subsequence betweeen them.
        if (text1.size() == 0 || text2.size() == 0)
            return 0;

        // Initialize the memo table to be all -1's to indicate
        // that the memos have not been filled out.
        for (int i = 0; i < 1001; ++i)
            for (int j = 0; j < 1001; ++j)
                memo[i][j] = -1;

        this->text1 = text1;
        this->text2 = text2;

        return lcs(0, 0);
    }
};