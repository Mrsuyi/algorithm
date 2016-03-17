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
	void moveZeroes(vector<int>& nums)
	{
		for (int i = 0, j = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0)
			{
				if (i != j)
				{
					nums[j] = nums[i];
					nums[i] = 0;
				}
				j++;
			}
		}
	}
};

int main()
{
	while (getchar());

	return 0;
}