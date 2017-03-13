class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<vector<string>> res;
        vector<int> queen(n);
        dfs(res, queen, n, 0);
        return res;
    }

    void dfs(vector<vector<string>>& res, vector<int>& queen, int n, int k)
    {
        // end
        if (k == n)
        {
            res.push_back(vector<string>(n, string(n, '.')));
            for (int i = 0; i < n; ++i)
                res.back()[i][queen[i]] = 'Q';
            return;
        }
        // try every place
        for (int i = 0; i < n; ++i)
        {
            // check previous queens
            bool conflict = false;
            for (int j = 0; j < k; ++j)
            {
                if (queen[j] == i || std::abs(queen[j] - i) == k - j)
                {
                    conflict = true;
                    break;
                }
            }

            if (!conflict)
            {
                queen[k] = i;
                dfs(res, queen, n, k + 1);
            }
        }
    }
};
