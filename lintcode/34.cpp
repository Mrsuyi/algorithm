class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        vector<int> qs(n);
        return helper(qs, 0);
    }

    int helper(vector<int>& qs, int idx)
    {
        if (idx == qs.size())
            return 1;
            
        int res = 0;
        for (int i = 0; i < qs.size(); ++i)
        {
            bool conflict = false;
            for (int j = 0; j < idx; ++j)
            {
                if (qs[j] == i || std::abs(qs[j] - i) == idx - j)
                {
                    conflict = true;
                    break;
                }
            }
            if (!conflict)
            {
                qs[idx] = i;
                res += helper(qs, idx + 1);
            }
        }
        return res;
    }
};
