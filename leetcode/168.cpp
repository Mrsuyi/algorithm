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
public:
	string convertToTitle(int n)
	{
		string ret;

		while (n)
		{
			n--;
			ret += n % 26 + 'A';
			n /= 26;
		}
		reverse(ret.begin(), ret.end());

		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}