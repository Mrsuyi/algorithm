class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); ++i)
        {
            dp[i][i] = true;
            if (i > 0) dp[i][i - 1] = true;

            for (int j = 0; j < i; ++j)
            {
                dp[j][i] = s[j] == s[i] && dp[j + 1][i - 1];
            }
        }
        
        vector<vector<string>> res;
        vector<string> path;
        search(res, dp, s, path, 0);
        return res;
    }

    void search(vector<vector<string>>& res, vector<vector<bool>>& dp, const string& s, vector<string>& path, int idx)
    {
        if (idx >= s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = idx; i < s.size(); ++i)
        {
            if (dp[idx][i])
            {
                path.push_back(s.substr(idx, i - idx + 1));
                search(res, dp, s, path, i + 1);
                path.pop_back();
            }
        }
    }
};