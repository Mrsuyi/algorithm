#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() == 0) return 0;

		vector<int> ret;

		ret.push_back(nums[0]);

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] != ret.back())
			{
				ret.push_back(nums[i]);
			}
		}

		nums = ret;

		return ret.size();
	}
};

int main()
{
	Solution solution;

	vector<int> inputs;
	int count;

	cin >> count;
	while (count--)
	{
		int input;
		cin >> input;
		inputs.push_back(input);
	}

	cout << solution.removeDuplicates(inputs) << endl;

	while (getchar());

	return 0;
}