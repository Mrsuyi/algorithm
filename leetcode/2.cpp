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
	int lengthOfLongestSubstring(string s)
	{
		int ret = 0;
		int len = s.length();
		int cnt = 0;
		bool flg[128] = { false };

		for (int bgn = 0, end = 0; end < len; end++)
		{
			if (flg[s[end]])
			{
				ret = max(ret, cnt);
				
				while (flg[s[end]])
				{
					flg[s[bgn]] = false;
					bgn++;
					cnt--;
				}
			}
			flg[s[end]] = true;
			cnt++;
		}

		return max(cnt, ret);
	}
};

int main()
{

	while (getchar());

	return 0;
}