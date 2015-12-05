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
	vector<string> letterCombinations(string digits)
	{
		if (digits.size() == 0) return{};

		vector<string> ret = { "" };

		int len = digits.size();
		for (int i = 0; i < len; i++)
		{
			vector<string> tmp;

			int cnt = ret.size();
			for (int j = 0; j < cnt; j++)
			{
				char bgn = 'a' + (digits[i] - '2') * 3;

				switch (digits[i])
				{
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
						tmp.push_back(ret[j] + bgn++);
						tmp.push_back(ret[j] + bgn++);
						tmp.push_back(ret[j] + bgn++);
						break;

					case '7':
						tmp.push_back(ret[j] + 'p');
						tmp.push_back(ret[j] + 'q');
						tmp.push_back(ret[j] + 'r');
						tmp.push_back(ret[j] + 's');
						break;

					case '8':
						tmp.push_back(ret[j] + 't');
						tmp.push_back(ret[j] + 'u');
						tmp.push_back(ret[j] + 'v');
						break;

					case '9':
						tmp.push_back(ret[j] + 'w');
						tmp.push_back(ret[j] + 'x');
						tmp.push_back(ret[j] + 'y');
						tmp.push_back(ret[j] + 'z');
						break;
				}
			}

			ret = tmp;
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}