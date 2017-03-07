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
	bool isAdditiveNumber(string num)
	{
		int len = num.length();

		// enum first num
		int max_1 = num[0] == '0' ? 1 : ((len + 1) >> 1) - 1;
		for (int i = 0; i < max_1; i++)
		{
			// enum second num
			int max_2 = num[i + 1] == '0' ? i + 2 : len;
			for (int j = i + 1; j < max_2; j++)
			{
				if ((len - j - 1) < max(i + 1, j - i)) break;

				long long n1 = stoll(string(num.begin(), num.begin() + i + 1));
				long long n2 = stoll(string(num.begin() + i + 1, num.begin() + j + 1));

				bool flag = true;
				int k = j + 1;

				// check rest of str
				while (k < len)
				{
					string nxt = to_string(n1 + n2);
					int l = nxt.length();

					long long n = stoll(string(num.begin() + k, min(num.begin() + k + l, num.end())));
					if (n != n1 + n2)
					{
						flag = false;
						break;
					}

					n1 = n2;
					n2 = n;
					k += l;
				}
				if (flag) return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}