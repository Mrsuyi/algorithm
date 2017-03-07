#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		int i = 0;
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[j] != val)
			{
				nums[i++] = nums[j];
			}
		}
		return i;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}