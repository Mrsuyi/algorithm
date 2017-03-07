class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        if (A.size() < 3) return;
        for (int i = 0, j = 0; i < A.size() && j < A.size();)
        {
            if (A[i] < 0 && (i > j || i & 1))
            {
                std::swap(A[i], A[j]);
                j += 2;
            }
            else
                ++i;
        }
        if ((A[A.size() - 1] < 0 && A[A.size() - 2] < 0) ||
            (A[A.size() - 1] > 0 && A[A.size() - 2] > 0))
            std::reverse(A.begin(), std::prev(A.end()));
    }
};