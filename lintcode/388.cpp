class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        vector<bool> chosen(n, false);
        string res;
        for (int i = 0; i < n; ++i)
        {
            int f = factorial(n - i - 1);
            int n = (k - 1) / f;
            k -= n * f;
            for (int j = 0;; ++j)
            {
                if (chosen[j]) continue;
                if (n-- == 0)
                {
                    chosen[j] = true;
                    res.push_back(j + '1');
                    break;
                }
            }
        }
        return res;
    }

    int factorial(int n)
    {
        int res = 1;
        for (int i = 2; i <= n; ++i)
            res *= i;
        return res;
    }
};