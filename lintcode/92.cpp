
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        for (int num : A)
            for (int i = m; i >= num; --i)
                if (dp[i - num])
                    dp[i] = true;

        for (int i = m; i >= 0; --i)
            if (dp[i])
                return i;
        return 0;
    }
};