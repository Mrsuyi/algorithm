#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
	string getPermutation(int n, int k)
	{
		int factorial[9] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320 };
		string ret;
		k--;
		unsigned nums = 0xFFFFFFFF;

		for (int i = n - 1; i >= 0; i--)
		{
			int num = (k / factorial[i]) + 1;
			k %= factorial[i];

			int j = 0;
			while (num)
			{
				if (nums & (1UL << j++)) num--;
			}

			ret += '0' + j--;
			nums &= ~(1 << j);
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	cout << solution.getPermutation(3, 1) << endl;
	cout << solution.getPermutation(3, 2) << endl;
	cout << solution.getPermutation(3, 3) << endl;
	cout << solution.getPermutation(3, 4) << endl;
	cout << solution.getPermutation(3, 5) << endl;
	cout << solution.getPermutation(3, 6) << endl;

	while (getchar());

	return 0;
}