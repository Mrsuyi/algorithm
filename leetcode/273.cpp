#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
private:
	string nums[20] =
	{
		"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
		"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
	};

	string mul_10[10] =
	{
		"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
	};

	string mul_1000[4] = { "Billion", "Million", "Thousand", "" };

public:
	string numberToWords(int num)
	{
		string ret;

		if (num == 0) return "Zero";

		int quo[4] = { 0 };
		
		for (int i = 3; num; i--)
		{
			quo[i] = num % 1000;
			num /= 1000;
		}

		for (int i = 0; i < 4; i++)
		{
			if (quo[i]) ret += sec(quo[i]) + ' ' + mul_1000[i] + ' ';
		}

		while (ret.back() == ' ') ret.pop_back();
		return ret;
	}

	string sec(int num)
	{
		string ret;

		ret += num / 100 ? nums[num / 100] + " Hundred " : "";
		num %= 100;
		ret += num >= 20 ? (mul_10[num / 10] + ' ' + nums[num % 10]) : nums[num];

		while (ret.back() == ' ') ret.pop_back();
		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}