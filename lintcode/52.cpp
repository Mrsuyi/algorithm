class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int i = nums.size() - 2;
        for (; i >= 0; --i)
        {
            auto it = std::lower_bound(nums.begin() + i + 1, nums.end(), nums[i], [](const int a, const int b)
            {
                return a > b;
            });
            if (it != nums.begin() + i + 1)
            {
                --it;
                std::swap(nums[i], *it);
                std::sort(nums.begin() + i + 1, nums.end());
                return nums;
            }
        }
        if (i == -1)
            std::reverse(nums.begin(), nums.end());
        return nums;
    }
};