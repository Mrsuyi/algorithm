class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = 0; j < B.size(); ++j)
            {
                dp[i + 1][j + 1] = std::max(std::max(dp[i][j + 1], dp[i + 1][j]), A[i] == B[j] ? (dp[i][j] + 1) : 0);
            }
        }
        return dp[A.size()][B.size()];
    }
};
