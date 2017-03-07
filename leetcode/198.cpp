#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int rob(vector<int>& nums)
	{
		if (nums.size() == 0) return 0;

		int yes = nums[0];
		int no = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			int tmp = yes;
			yes = nums[i] + no;
			no = tmp > no ? tmp : no;
		}

		return yes > no ? yes : no;
	}
};

int main()
{
	Solution solution;


	while (getchar());

	return 0;
}