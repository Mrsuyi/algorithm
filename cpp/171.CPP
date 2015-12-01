#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int titleToNumber(string s)
	{
		int ret = 0;

		for (auto i = s.begin(); i != s.end(); i++)
		{
			ret *= 26;
			ret += *i - 'A' + 1;
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
		cout << solution.titleToNumber(input) << endl;
	}

	while (getchar());

	return 0;
}