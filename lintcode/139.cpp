class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        vector<pair<int, int>> sums(nums.size() + 1, {0, -1});
        for (int i = 0; i < nums.size(); ++i)
        {
            sums[i + 1].first = sums[i].first + nums[i];
            sums[i + 1].second = i;
        }

        std::sort(sums.begin(), sums.end());
        vector<int> res = {0, 0};
        int diff = std::abs(nums[0]);
        for (int i = 1; i < sums.size(); ++i)
            if (sums[i].first - sums[i - 1].first < diff)
            {
                diff = sums[i].first - sums[i - 1].first;
                int a = sums[i].second;
                int b = sums[i - 1].second;
                res = {std::min(a, b) + 1, std::max(a, b)};
            }
        return res;
    }
};
