#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int maximumGap(vector<int>& nums)
	{
		int len = nums.size();
		if (len < 2) return 0;
		int mi = *min_element(nums.begin(), nums.end());
		int mx = *max_element(nums.begin(), nums.end());
		if (mi == mx) return 0;
		
		double div = double(mx - mi) / len;
		vector<int> bmin(len + 1, INT_MAX);
		vector<int> bmax(len + 1, INT_MIN);

		for (int n : nums)
		{
			int idx = double(n - mi) / div;
			bmin[idx] = min(bmin[idx], n);
			bmax[idx] = max(bmax[idx], n);
		}

		int ret = INT_MIN;
		for (int i = 1, bgn = bmax[0]; i <= len; i++)
		{
			if (bmin[i] != INT_MAX)
			{
				ret = max(ret, bmin[i] - bgn);
				bgn = bmax[i];
			}
		}
		return ret;
	}
};

int main()
{

	while (getchar());

	return 0;
}