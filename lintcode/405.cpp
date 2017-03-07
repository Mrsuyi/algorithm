class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
        int m = matrix.size();
        if (m == 0) return {{0, 0}, {0, 0}};
        int n = matrix[0].size();
        if (n == 0) return {{0, 0}, {0, 0}};
      
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            sum[i + 1][j + 1] = matrix[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];

        vector<vector<int>> res(2, vector<int>(2));
        for (int i = 0; i < m; ++i)
        for (int j = i; j < m; ++j)
        {
            unordered_map<int, int> record;
            record[0] = 0;
            for (int k = 0; k < n; ++k)
            {
                int diff = sum[j + 1][k + 1] - sum[i][k + 1];
                if (record.count(diff))
                {
                    res[0][0] = i;
                    res[0][1] = record[diff];
                    res[1][0] = j;
                    res[1][1] = k;
                    goto end;
                }
                else
                    record[diff] = k + 1;
            }
        }
end:
        return res;
    }
};