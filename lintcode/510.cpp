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


//
// another DP
//
class Solution {
public:
    /**
     * @param matrix a boolean 2D matrix
     * @return an integer
     */
    int maximalRectangle(vector<vector<bool> > &matrix) {
        // Write your code here
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        int res = 0;
        vector<int> h(n, 0);
        vector<int> l(n, INT_MAX);
        vector<int> r(n, INT_MAX);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0, len = 0; j < n; ++j)
            {
                if (matrix[i][j])
                {
                    ++h[j];
                    l[j] = std::min(l[j], ++len);
                }
                else
                {
                    h[j] = 0;
                    l[j] = INT_MAX;
                    len = 0;
                }
            }
            for (int j = n - 1, len = 0; j >= 0; --j)
            {
                if (matrix[i][j])
                {
                    r[j] = std::min(r[j], ++len);
                }
                else
                {
                    r[j] = INT_MAX;
                    len = 0;
                }
            }

            for (int j = 0; j < n; ++j)
                if (matrix[i][j])
                    res = std::max(res, (l[j] + r[j] - 1) * h[j]);
        }
        return res;
    }
};