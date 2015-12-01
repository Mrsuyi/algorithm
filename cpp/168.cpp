#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	string convertToTitle(int n)
	{
		string ret;

		while (n > 0)
		{
			ret += ((n - 1) % 26) + 'A';
			n = (n - 1) / 26;
		}

		reverse(ret.begin(), ret.end());

		return ret;
	}
};

int main()
{
	Solution solution;

	int input;

	while (cin >> input)
	{
		cout << solution.convertToTitle(input) << endl;
	}

	while (getchar());

	return 0;
}