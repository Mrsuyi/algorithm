#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

#define UP   0
#define DOWN 1

using namespace std;

class Solution
{
public:

	string convert(string s, int numRows)
	{
		if (numRows == 1) return s;

		string ret;
		int len   = s.length();
		int z_len = ((numRows - 1) * 2);
		int z_cnt = (s.length() / z_len) + (s.length() % z_len != 0);

		// line 0
		for (int i = 0; i < z_cnt; i++)
		{
			ret += s[i * z_len];
		}

		// line 1 ~ numRows-2
		for (int i = 1; i < numRows - 1; i++)
		{
			for (int j = 0; j < z_cnt; j++)
			{
				int i1 = j * z_len + i;
				int i2 = (j + 1) * z_len - i;

				if (i1 < len) ret += s[i1];
				if (i2 < len) ret += s[i2];
			}
		}

		// line numRows-1
		for (int i = 0; i < z_cnt; i++)
		{
			int i1 = i * z_len + numRows - 1;
			if (i1 < len) ret += s[i1];
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	string input;
	int    row;

	while (cin >> input)
	{
		cin >> row;

		string result = solution.convert(input, row);

		cout << result << endl;
	}

	while (getchar());

	return 0;
}