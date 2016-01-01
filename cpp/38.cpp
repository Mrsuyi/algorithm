#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	string countAndSay(int n)
	{
		string pre = "1";
		while (--n > 0)
		{
			string nxt;
			for (int i = 0; i < pre.size();)
			{
				int same = 0;
				for (i++; i < pre.size() && pre[i] == pre[i - 1]; i++, same++) {}
				nxt += '1' + same;
				nxt += pre[i - 1];
			}
			pre = nxt;
		}
		return pre;
	}
};

int main()
{
	while (getchar());

	return 0;
}