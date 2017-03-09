class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        if (nums.size() == 0) return {{}};
        
        vector<vector<int>> res;
        int len = nums.size();

        vector<bool> taken(nums.size(), false);
        vector<int> stk = {0};
        while (!stk.empty())
        {
            if (stk.back() == len)
            {
                stk.pop_back();
                if (stk.empty()) break;
                taken[stk.back()] = false;
                ++stk.back();
            }
            else if (taken[stk.back()])
            {
                ++stk.back();
            }
            else
            {
                if (stk.size() == len)
                {
                    vector<int> path(len);
                    for (int i = 0; i < len; ++i)
                        path[i] = nums[stk[i]];
                    res.push_back(path);
                    stk.back() = len;
                }
                else
                {
                    taken[stk.back()] = true;
                    stk.push_back(0);
                }
            }
        }
        return res;
    }
};