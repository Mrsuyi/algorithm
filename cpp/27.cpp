#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		vector<int> ret;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
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
	int remove;

	cin >> count;
	while (count--)
	{
		int input;
		cin >> input;
		inputs.push_back(input);
	}

	cin >> remove;

	cout << solution.removeElement(inputs, remove) << endl;

	while (getchar());

	return 0;
}