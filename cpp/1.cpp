#include <cstdio>
#include <vector>
#include <unordered_map>

#define _CRT_SECURE_NO_WARNINGS
#define scanf scanf_s

using namespace std;

typedef unordered_map<int, int> umap;

class Solution
{
public:

	umap map;

	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;

		for (int i = 0; i < nums.size(); i++)
		{
			umap::iterator rest = map.find(target - nums[i]);

			if (rest != map.end())
			{
				result.push_back(rest->second + 1);
				result.push_back(i + 1);

				return result;
			}
			else
			{
				map.insert({ nums[i], i });
			}
		}
	}
};

int main()
{
	Solution solution;
	vector<int> inputs;
	int input;
	int target;

	scanf("%d", &target);
	while (scanf("%d", &input))
	{
		inputs.push_back(input);
	}

	vector<int> result = solution.twoSum(inputs, target);
	printf("%d %d", result[0], result[1]);

	while (getchar());
	return 0;
}