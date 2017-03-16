class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        vector<int> l(nums.size() + 1, INT_MIN);
        vector<int> r(nums.size() + 1, INT_MIN);

        for (int i = 0, sum = 0; i < nums.size(); ++i)
        {
            if (sum < 0) sum = 0;
            l[i + 1] = std::max(l[i], sum += nums[i]);
        }
        for (int i = nums.size() - 1, sum = 0; i >= 0; --i)
        {
            if (sum < 0) sum = 0;
            r[i] = std::max(r[i + 1], sum += nums[i]);
        }

        int res = INT_MIN;
        for (int i = 1; i < nums.size(); ++i)
            res = std::max(res, l[i] + r[i]);
        return res;
    }
};
