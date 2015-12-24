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
		int len = s.length();
		int ret = 0;
		int cnt = 0;
		int bgn = 0;
		bool flg[128] = { false };

		for (int i = 0; i < len; i++)
		{
			if (flg[s[i]])
			{
				ret = max(ret, cnt);
				
				while (flg[s[i]])
				{
					flg[s[bgn]] = false;
					bgn++;
					cnt--;
				}
			}
			flg[s[i]] = true;
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