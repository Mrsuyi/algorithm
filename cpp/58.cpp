#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		if (s == "") return 0;

		int i = s.size() - 1;

		while (i > 0 && s[i] == ' ') { i--; }

		if (s[i] == ' ') return 0;

		int len = 0;
		while (i >= 0 && s[i] != ' ') { i--; len++; }

		return len;
	}
};

int main()
{
	Solution solution;

	while (true)
	{
		string input;

		getline(cin, input);

		cout << solution.lengthOfLastWord(input) << endl;
	}

	while (getchar());

	return 0;
}