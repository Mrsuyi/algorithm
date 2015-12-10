#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
private:
	inline int min(const int a, const int b) { return a < b ? a : b; };
public:
	int minimumTotal(vector<vector<int>>& triangle)
	{
		int levels = triangle.size();

		for (int i = levels - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}

		return triangle[0][0];
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}