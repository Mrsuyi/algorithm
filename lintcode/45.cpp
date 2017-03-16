class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        vector<int> lmin(nums.size() + 1, INT_MAX);
        vector<int> lmax(nums.size() + 1, INT_MIN);
        vector<int> rmin(nums.size() + 1, INT_MAX);
        vector<int> rmax(nums.size() + 1, INT_MIN);

        for (int i = 0, smin = 0, smax = 0; i < nums.size(); ++i)
        {
            if (smin > 0) smin = 0;
            if (smax < 0) smax = 0;
            lmin[i + 1] = std::min(lmin[i], smin += nums[i]);
            lmax[i + 1] = std::max(lmax[i], smax += nums[i]);
        }
        for (int i = nums.size() - 1, smin = 0, smax = 0; i >= 0; --i)
        {
            if (smin > 0) smin = 0;
            if (smax < 0) smax = 0;
            rmin[i] = std::min(rmin[i + 1], smin += nums[i]);
            rmax[i] = std::max(rmax[i + 1], smax += nums[i]);
        }
        
        int res = 0;
        for (int i = 1; i < nums.size(); ++i)
            res = std::max(res, std::max(lmax[i] - rmin[i], rmax[i] - lmin[i]));
        return res;
    }
};
