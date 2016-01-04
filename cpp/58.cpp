#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		int i = s.size() - 1;
		while (i >= 0 && s[i] == ' ') { i--; }
		int len = 0;
		while (i >= 0 && s[i] != ' ') { i--; len++; }
		return len;
	}
};

int main()
{
	while (getchar());

	return 0;
}