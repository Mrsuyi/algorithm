class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        vector<vector<int>> cnts(T.size() + 1, vector<int>(S.size() + 1, 0));
        cnts[0] = vector<int>(S.size() + 1, 1);

        for (int i = 0; i < T.size(); ++i)
        {
            for (int j = 0; j < S.size(); ++j)
            {
                cnts[i + 1][j + 1] = cnts[i + 1][j] + (T[i] == S[j] ? cnts[i][j] : 0);
            }
        }

        return cnts[T.size()][S.size()];
    }
};
