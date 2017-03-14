class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        vector<int> nums = {1};
        for (int i2 = 0, i3 = 0, i5 = 0, i = 1; i < n; ++i)
        {
            int nxt = std::min(nums[i2] * 2, std::min(nums[i3] * 3, nums[i5] * 5));
            nums.push_back(nxt);
            if (nums[i2] * 2 == nums.back()) ++i2;
            if (nums[i3] * 3 == nums.back()) ++i3;
            if (nums[i5] * 5 == nums.back()) ++i5;
        }
        return nums.back();
    }
};