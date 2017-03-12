class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> res = {0};
        for (int i = 0; i < n; ++i)
            for (int j = (1 << i) - 1; j >= 0; --j)
                res.push_back(res[j] | 1 << i);
        return res;
    }
};