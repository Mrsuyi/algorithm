#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	void moveZeroes(vector<int>& nums) 
	{
		int zero = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				zero++;
			}
			else
			{
				nums[i - zero] = nums[i];
			}
		}
		for (int i = nums.size() - 1; zero > 0; i--, zero--)
		{
			nums[i] = 0;
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}