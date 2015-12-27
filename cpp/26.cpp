#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		int len = nums.size();
		int i = 0, j = 1;
		while (j < len)
		{
			if (nums[j] != nums[i])
			{
				nums[++i] = nums[j];
			}
			j++;
		}
		return len ? i + 1 : 0;
	}
};

int main()
{
	while (getchar());

	return 0;
}