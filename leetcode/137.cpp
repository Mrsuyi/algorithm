#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int cnt_1 = 0, cnt_2 = 0, cnt_3 = 0;
		for (int n : nums)
		{
			cnt_2 |= cnt_1 & n;
			cnt_1 ^= n;
			cnt_3 = cnt_1 & cnt_2;
			cnt_1 &= ~cnt_3;
			cnt_2 &= ~cnt_3;
		}
		return cnt_1;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}