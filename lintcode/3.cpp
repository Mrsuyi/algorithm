class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        if (k == 0 && n == 0) return 1;

        int res = 0;
        for (int mul10 = 1, post = 0; n;)
        {
            int cur = n % 10;
            n /= 10;

            if (k == 0 && n == 0)
                break;

            if (k < cur)
                res += (n + 1) * mul10;
            else if (k == cur)
                res += n * mul10 + post + 1;
            else
                res += n * mul10;

            post += mul10 * cur;
            mul10 *= 10;
        }
        return res;
    }
};