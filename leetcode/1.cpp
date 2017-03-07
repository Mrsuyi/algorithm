#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> map;

		for (int i = 0; i < nums.size(); i++)
		{
			auto idx = map.find(target - nums[i]);

			if (idx != map.end())
			{
				return { idx->second + 1 , i + 1 };
			}
			else
			{
				map[nums[i]] = i;
			}
		}
	}
};

int main()
{
	while (getchar());

	return 0;
}