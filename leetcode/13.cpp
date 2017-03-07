#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int romanToInt(string s)
	{
		int ret = 0;
		int len = s.length();
		int pre = INT_MAX;
		int cur = 0;

		int nums[128];
		nums['I'] = 1;
		nums['V'] = 5;
		nums['X'] = 10;
		nums['L'] = 50;
		nums['C'] = 100;
		nums['D'] = 500;
		nums['M'] = 1000;

		for (int i = 0; i < len; i++)
		{
			cur = nums[s[i]];
			ret += cur;
			if (cur > pre) ret -= 2 * pre;
			pre = cur;
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	string input;

	while (cin >> input)
	{
		cout << solution.romanToInt(input) << endl;
	}

	while (getchar());

	return 0;
}