#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	bool isIsomorphic(string s, string t)
	{
		char map[128] = { 0 };
		bool f_in[128] = { 0 };
		bool f_out[128] = { 0 };

		for (int i = 0; i < s.size(); i++)
		{
			char in = s[i];
			char out = t[i];

			if (f_in[in])
			{
				if (map[in] != out)
				{
					return false;
				}
			}
			else
			{
				if (f_out[out])
				{
					return false;
				}
				else
				{
					f_in[in] = true;
					f_out[out] = true;
					map[in] = out;
				}
			}
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