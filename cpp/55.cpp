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
	inline int max(int a, int b) { return a > b ? a : b; }
public:
	bool canJump(vector<int>& nums)
	{
		int len = nums.size();
		int last = len - 1;
		int far = 0;

		for (int i = 0; i < len; i++)
		{
			if (far < i) return false;

			far = max(far, i + nums[i]);

			if (far >= last) return true;
		}
		return true;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}