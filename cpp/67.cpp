#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
	inline string single(string input, bool carry)
	{
		if (!carry) return input;
	
		string ret;

		auto i = input.begin();

		while (i != input.end() && *i == '1')
		{
			ret += '0';
			i++;
		}

		if (i != input.end())
		{
			ret += '1';
			i++;
			ret += string(i, input.end());
		}
		else
		{
			ret += '1';
		}

		return ret;
	}

public:
	string addBinary(string a, string b)
	{
		string ret;

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		auto ia = a.begin();
		auto ib = b.begin();

		unsigned carry = 0;

		for (; ia != a.end() && ib != b.end(); ia++, ib++)
		{
			unsigned add = (*ia - '0') + (*ib - '0') + carry;

			ret += ('0' + (add & 1UL));
			carry = add >> 1;
		}

		if (ia != a.end())
		{
			ret += single(string(ia, a.end()), carry);
		}
		else if (ib != b.end())
		{
			ret += single(string(ib, b.end()), carry);
		}
		else if (carry)
		{
			ret += '1';
		}

		reverse(ret.begin(), ret.end());

		return ret;
	}
};

int main()
{
	Solution solution;

	string s1, s2;

	while (true)
	{
		cin >> s1;
		cin >> s2;

		cout << solution.addBinary(s1, s2) << endl;
	}

	while (getchar());

	return 0;
}