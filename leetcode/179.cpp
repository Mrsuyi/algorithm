#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
private:
	static bool cmp(const string& a, const string& b)
	{
		return a + b > b + a;
	}

public:
	string largestNumber(vector<int>& nums)
	{
		string ret;

		vector<string> strs;

		for (int n : nums)
		{
			strs.push_back(to_string(n));
		}

		sort(strs.begin(), strs.end(), cmp);

		for (string& str : strs)
		{
			ret += str;
		}

		if (ret[0] == '0' && ret.size() > 0) return "0";

		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}