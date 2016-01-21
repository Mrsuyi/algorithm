#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	char character(char c)
	{
		return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ? c :
			   (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : 0;
	}

	bool isPalindrome(string s)
	{
		int len = s.size() - 1;
		for (int l = 0, r = len; l < r; l++, r--)
		{
			while (l < len && !character(s[l])) l++;
			while (r >= 0 && !character(s[r])) r--;

			if (l < r && character(s[l]) != character(s[r])) return false;
		}

		return true;
	}
};

int main()
{
	Solution solution;

	string input;

	while (getline(cin, input))
	{
		cout << solution.isPalindrome(input) << endl;
	}

	return 0;
}