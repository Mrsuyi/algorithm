#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
	vector<int> diffWaysToCompute(string input)
	{
		vector<int> nums;
		vector<char> oprs;

		int len = input.length();
		int num = 0;
		for (int i = 0; i < len; i++)
		{
			char c = input[i];
			if (c >= '0' && c <= '9')
			{
				num = 10 * num + c - '0';
			}
			else
			{
				nums.push_back(num);
				num = 0;
				oprs.push_back(c);
			}
		}
		nums.push_back(num);

		return search(nums, oprs, 0, oprs.size() - 1);
	}

	int cal(int a, int b, char opr)
	{
		switch (opr)
		{
			case '+': return a + b;
			case '-': return a - b;
			case '*': return a * b;
			case '/': return a / b;
		}
	}

	vector<int> search(vector<int>& nums, vector<char>& oprs, int l, int r)
	{
		if (l > r) return { nums[l] };
		if (l == r) return { cal(nums[l], nums[l + 1], oprs[l]) };

		vector<int> ret;
		for (int i = l; i <= r; i++)
		{
			vector<int> vl = search(nums, oprs, l, i - 1);
			vector<int> vr = search(nums, oprs, i + 1, r);

			char opr = oprs[i];
			for (auto n1 : vl)
			for (auto n2 : vr)
			{
				ret.push_back(cal(n1, n2, opr));
			}
		}
		return ret;
	}
};

int main()
{
	Solution solution;

	solution.diffWaysToCompute("1+1");

	while (getchar());

	return 0;
}