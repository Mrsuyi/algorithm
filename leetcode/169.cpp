#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		int val = nums[0];
		int cnt = 1;

		for (int i = 1; i < nums.size(); i++)
		{
			if (cnt == 0)
			{
				val = nums[i];
				cnt = 1;
			}
			else
			{
				if (nums[i] == val)
				{
					cnt++;
				}
				else
				{
					cnt--;
				}
			}
		}
		
		return val;
	}
};

int main()
{
	Solution solution;

	int count;
	vector<int> inputs;

	cin >> count;

	while (count--)
	{
		int input;
		cin >> input;
		inputs.push_back(input);
	}

	cout << solution.majorityElement(inputs) << endl;

	while (getchar());

	return 0;
}