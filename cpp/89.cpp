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
	vector<int> grayCode(int n)
	{
		if (n == 0) return { 0 };

		vector<int> ret = { 0, 1 };

		for (int i = 1; i < n; i++)
		{
			int base = 1 << i;

			for (int j = base - 1; j >= 0; j--)
			{
				ret.push_back(base | (ret[j]));
			}
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}