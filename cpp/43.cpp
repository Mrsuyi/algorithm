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

		vector<int> digits;
		int len1 = num1.length();
		int len2 = num2.length();
		int max_len = num1.length() + num2.length();

		digits.reserve(max_len + 1);

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		
		// multiply each digit
		for (int i = 0; i < max_len; i++)
		{
			int sum = 0, n1 = 0, n2 = i - n1;

			while (n2 >= len2) { n1++; n2--; }

			while (n1 < len1 && n2 >= 0) { sum += (num1[n1++] - '0') * (num2[n2--] - '0'); }

			digits.push_back(sum);
		}

		// add up
		string ret;
		for (int i = 0; i < max_len; i++)
		{
			ret += '0' + digits[i] % 10;
			digits[i + 1] += digits[i] / 10;
		}

		// eliminate 0
		reverse(ret.begin(), ret.end());
		int i = 0;
		while (ret[i] == '0') { i++; }

		return string(ret, i);
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}