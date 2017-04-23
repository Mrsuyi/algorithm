#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int n, m;
        cin >> n >> m;
        vector<int> nums(n + 2);
        nums[0] = 0;
        nums[n + 1] = 101;
        for (int i = 0; i < n; ++i)
            cin >> nums[i + 1];
        if (m >= n || n == 0)
        {
            cout << 100 << endl;
        }
        else
        {
            int res = INT_MIN;
            for (int j = 1; j + m <= n + 1; ++j)
            {
                res = max(res, nums[j + m] - nums[j - 1] - 1);
            }
            cout << res << endl;
        }
    }
    
    return 0;
};