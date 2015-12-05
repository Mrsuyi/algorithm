#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		sort(nums.begin(), nums.end());

		int sum;
		int diff = INT_MAX;

		int i_end = nums.size() - 2;

		for (int i = 0; i < i_end; i++)
		{
			int j = i + 1, k = i_end + 1;

			while (j < k)
			{
				int s = nums[i] + nums[j] + nums[k];
				int d = target - s;

				if (d == 0) return s;

				d > 0 ? j++ : k--;

				d = abs(d);
				if (d < diff)
				{
					diff = d;
					sum = s;
				}
			}
		}

		return sum;
	}
};

int main()
{
	Solution solution;

	vector<int> input = { 1, 1, 1, 0 };

	cout << solution.threeSumClosest(input, -100) << endl;

	while (getchar());

	return 0;
}