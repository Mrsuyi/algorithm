#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		//return haystack.find(needle, 0); // (～￣▽￣)～

	}
};

int main()
{
	Solution solution;

	string haystack;
	string needle;

	cin >> haystack;
	cin >> needle;

	cout << solution.strStr(haystack, needle) << endl;

	while (getchar());

	return 0;
}