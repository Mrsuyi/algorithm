class Solution {
public:
    /**
     * @param matrix a boolean 2D matrix
     * @return an integer
     */
    int helper(vector<int>& nums)
    {
        int res = 0;
        nums.push_back(0);
        vector<int> stk = {-1};
        for (int i = 0; i < nums.size(); ++i)
        {
            while (!stk.empty() && nums[stk.back()] > nums[i])
            {
                int h = stk.back();
                stk.pop_back();
                res = std::max(res, nums[h] * (i - stk.back() - 1));
            }
            stk.push_back(i);
        }
        return res;
    }

    int maximalRectangle(vector<vector<bool> > &matrix) {
        // Write your code here
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        int res = 0;
        vector<int> heights(n, 0);
        for (int i = 0; i < m; ++i)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; ++j)
                cur[j] = matrix[i][j] ? (1 + heights[j]) : 0;
            res = std::max(res, helper(cur));
            std::swap(heights, cur);
        }
        return res;
    }
};