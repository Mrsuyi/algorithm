#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{	
		int l1 = a.size();
		int l2 = b.size();
		int l = max(l1, l2);
		string ret(l, '0');

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		a += string(l - l1, '0');
		b += string(l - l2, '0');

		int c = 0;
		for (int i = 0; i < l; i++)
		{
			int sum = a[i] - '0' + b[i] - '0' + c;
			ret[i] = '0' + (sum & 1);
			c = (sum & 2) >> 1;
		}
		if (c) ret.push_back('1');

		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main()
{
	Solution solution;

	solution.addBinary("11", "1");

	while (getchar());

	return 0;
}