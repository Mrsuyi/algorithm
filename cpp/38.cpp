#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
	vector<string> cache;

public:
	Solution()
	{
		cache.push_back("1");
	}

	string countAndSay(int n)
	{
		if (n <= cache.size()) return cache[n - 1];

		int count = n - cache.size();

		while (count--)
		{
			string pre = cache.back();
			string nxt;

			for (int i = 0; i < pre.size();)
			{
				int same = 0;

				for (i++; i < pre.size() && pre[i] == pre[i - 1]; i++, same++) {}

				nxt += '1' + same;
				nxt += pre[i - 1];
			}

			cache.push_back(nxt);
		}

		return cache.back();
	}
};

int main()
{
	Solution solution;

	int n;

	while (cin >> n)
	{
		cout << solution.countAndSay(n) << endl;
	}

	while (getchar());

	return 0;
}