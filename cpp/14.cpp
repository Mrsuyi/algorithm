#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:

	string longestCommonPrefix(vector<string>& strs)
	{
		if (strs.size() == 0)      return "";
		if (strs.size() == 1)      return strs[0];
		if (strs[0].length() == 0) return "";

		string ret;

		for (int i = 0;; i++)
		{
			char chr = strs[0][i];

			int j = 1;
			
			for (; j < strs.size() && strs[j].length() > i; j++)
			{
				if (strs[j][i] != chr) break;
			}

			if (j != strs.size())
			{
				return ret;
			}
			else
			{
				ret += chr;
			}
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	int count;
	vector<string> inputs;
	
	cin >> count;

	while (count--)
	{
		string input;
		cin >> input;
		inputs.push_back(input);
	}

	cout << solution.longestCommonPrefix(inputs) << endl;

	while (getchar());

	return 0;
}