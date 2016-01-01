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
	string multiply(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0") return "0";

		int l1 = num1.length();
		int l2 = num2.length();
		int l = num1.length() + num2.length();
		vector<int> digits(l);

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		for (int i = 0; i < l; i++)
		{
			int sum = 0, n1 = 0, n2 = i - n1;
			while (n2 >= l2) { n1++; n2--; }
			while (n1 < l1 && n2 >= 0) { sum += (num1[n1++] - '0') * (num2[n2--] - '0'); }
			digits[i] = sum;
		}

		string ret;
		for (int i = 0; i < l; i++)
		{
			ret += '0' + digits[i] % 10;
			digits[i + 1] += digits[i] / 10;
		}

		if (ret[l - 1] == '0') ret.pop_back();
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}