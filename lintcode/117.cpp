class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        if (A.size() == 0) return 0;

        for (int l = 0, r = 0, steps = 1;; ++steps)
        {
            int reach = 0;
            for (int i = l; i <= r; ++i)
                reach = std::max(reach, i + A[i]);
            if (reach >= A.size() - 1)
                return steps;
            l = r + 1;
            r = reach;
        }
        return 0;
    }
};