#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <functional>

using namespace std;

class Solution
{
public:
    int maxCoins(vector<int>& nums)
    {
        int len = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(len + 2, vector<int>(len + 2, 0));

        for (int size = 1; size <= len; size++)
        {
            for (int l = 1; l <= len - size + 1; l++)
            {
                int r = l + size - 1;

                for (int k = l; k <= r; k++)
                {
                    dp[l][r] = max(dp[l][r], dp[l][k - 1] + dp[k + 1][r] + nums[k] * nums[l - 1] * nums[r + 1]);
                }
            }
        }

        return dp[1][len];
    }
};

int main()
{
    vector<int> input = { 3,1,5,8 };
    Solution so;
    cout << so.maxCoins(input);

    while (getchar());

    return 0;
}