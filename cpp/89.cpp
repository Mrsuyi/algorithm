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
		vector<int> ret = { 0 };

		for (int i = 0; i < n; i++)
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