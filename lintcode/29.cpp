class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        if (s1.size() + s2.size() != s3.size()) return false;

        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        dp[0][0] = true;

        for (int j = 0; j < s2.size(); ++j)
            dp[0][j + 1] = s2[j] == s3[j] && dp[0][j];

        for (int i = 0; i < s1.size(); ++i)
        {
            dp[i + 1][0] = s1[i] == s3[i] && dp[i][0];

            for (int j = 0; j < s2.size(); ++j)
            {
                dp[i + 1][j + 1] = (s1[i] == s3[i + j + 1] && dp[i][j + 1]) ||
                                   (s2[j] == s3[i + j + 1] && dp[i + 1][j]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};