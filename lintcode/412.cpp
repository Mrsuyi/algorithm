class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        // Write your code here
        int len = ratings.size();
        if (len == 0) return 0;

        vector<int> nums(len, 1);
        queue<int> bfs;
        for (int i = 0; i < len; ++i)
        {
            if ((i == 0 || ratings[i] <= ratings[i - 1]) &&
                (i == len - 1 || ratings[i] <= ratings[i + 1]))
                bfs.push(i);
        }

        while (!bfs.empty())
        {
            int i = bfs.front();
            bfs.pop();

            if (i > 0)
            {
                if (ratings[i - 1] > ratings[i])
                {
                    if (nums[i - 1] == 1)
                        bfs.push(i - 1);
                    nums[i - 1] = std::max(nums[i - 1], nums[i] + 1);
                }
            }
            if (i < len - 1)
            {
                if (ratings[i + 1] > ratings[i])
                {
                    if (nums[i + 1] == 1)
                        bfs.push(i + 1);
                    nums[i + 1] = std::max(nums[i + 1], nums[i] + 1);
                }
            }
        }
        
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};