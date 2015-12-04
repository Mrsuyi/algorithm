#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int cnt[128] = { 0 };
		int max = 0;
		int len = 0;
		int bgn = 0;

		for (int i = 0; i < s.size(); i++)
		{
			// if same char appears
			if (cnt[s[i]])
			{
				// record length
				if (len > max) max = len;

				// remove first char of substr until same char vanish
				while (bgn < i && cnt[s[i]])
				{
					cnt[s[bgn]]--;
					bgn++;
					len--;
				}
			}

			// add this char
			cnt[s[i]]++;
			len++;
		}

		// compare last substr
		if (len > max) max = len;

		return max;
	}
};

int main()
{

	while (getchar());

	return 0;
}