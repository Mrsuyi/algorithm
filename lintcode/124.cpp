class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        int res = 0;
        unordered_map<int, int> lens;
        for (int n : num)
        {
            if (lens.count(n)) continue;
            int up = lens.count(n + 1) ? lens[n + 1] : 0;
            int dn = lens.count(n - 1) ? lens[n - 1] : 0;
            int len = up + dn + 1;
            lens[n + up] = len;
            lens[n - dn] = len;
            lens[n] = len;
            res = std::max(res, len);
        }
        return res;
    }
};