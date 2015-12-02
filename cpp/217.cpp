#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		unordered_map<int, bool> exist;

		for (int i = 0; i < nums.size(); i++)
		{
			if (exist[nums[i]])
			{
				return true;
			}
			else
			{
				exist[nums[i]] = true;
			}
		}

		return false;
	}
};

int main()
{
	Solution solution;


	while (getchar());

	return 0;
}