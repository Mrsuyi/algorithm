#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	inline char character(char c)
	{
		if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
		{
			return c;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			return c - 'A' + 'a';
		}
		else
		{
			return 0;
		}
	}

	bool isPalindrome(string s)
	{
		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			char left, right;

			for (; i < j && !(left = character(s[i])); i++) {}
			
			if (i == j) return true;
			
			for (; i < j && !(right = character(s[j])); j--) {}

			if (i == j) return true;

			if (left != right) return false;
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