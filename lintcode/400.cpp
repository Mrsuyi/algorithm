class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        // write your code here
        if (nums.size() == 0) return 0;
        int min = INT_MAX, max = INT_MIN;
        for (int num : nums)
        {
            min = std::min(min, num);
            max = std::max(max, num);
        }
        if (min == max) return 0;

        vector<pair<int, int>> buckets(nums.size(), {INT_MAX, -1});
        double bucket = double(max - min) / nums.size();
        for (int num : nums)
        {
            int idx = double(num - min) / bucket;
            if (idx >= nums.size())
                idx = nums.size() - 1;
            buckets[idx].first = std::min(buckets[idx].first, num);
            buckets[idx].second = std::max(buckets[idx].second, num);
        }
        int res = 0;
        for (int i = 1, m = buckets[0].second; i < nums.size(); ++i)
        {
            if (buckets[i].second != -1)
            {
                res = std::max(res, buckets[i].first - m);
                m = buckets[i].second;
            }
        }
        return res;
    }
};