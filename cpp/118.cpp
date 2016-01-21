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
	vector<vector<int>> generate(int numRows)
	{
		if (numRows == 0) return {};

		vector<vector<int>> ret = { { 1 } };
		for (int i = 1; i < numRows; i++)
		{
			ret.push_back(vector<int>(i + 1));
			ret[i][0] = 1;
			ret[i][i] = 1;

			for (int j = 1; j <= i / 2; j++)
			{
				ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
				ret[i][i - j] = ret[i][j];
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