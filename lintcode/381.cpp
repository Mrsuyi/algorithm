class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        vector<vector<int>> matrix(n, vector<int>(n));
        fill(matrix, 0, 0, n - 1, 1);
        return matrix;
    }

    void fill(vector<vector<int>>& matrix, int x, int y, int l, int n)
    {
        if (l == 0)
        {
            matrix[x][y] = n;
            return;
        }
        if (l < 0)
            return;

        for (int i = 0; i < l; ++i, ++n)
        {
            matrix[x][y + i] = n + 0 * l;
            matrix[x + i][y + l] = n + 1 * l;
            matrix[x + l][y + l - i] = n + 2 * l;
            matrix[x + l - i][y] = n + 3 * l;
        }
        fill(matrix, x + 1, y + 1, l - 2, n + 3 * l);
    }
};