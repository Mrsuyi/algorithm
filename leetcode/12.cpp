#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

#include <ctime>

using namespace std;

class Solution
{
public:
	string intToRoman(int num)
	{
		int n_1000 = num / 1000;
		num %= 1000;
		int n_100 = num / 100;
		num %= 100;
		int n_10 = num / 10;
		num %= 10;
		int n_1 = num;

		string ret;

		switch (n_1000)
		{
		case 3:
			ret += "MMM";
			break;
		case 2:
			ret += "MM";
			break;
		case 1:
			ret += "M";
			break;
		}

		switch (n_100)
		{
		case 9:
			ret += "CM";
			break;
		case 8:
			ret += "DCCC";
			break;
		case 7:
			ret += "DCC";
			break;
		case 6:
			ret += "DC";
			break;
		case 5:
			ret += "D";
			break;
		case 4:
			ret += "CD";
			break;
		case 3:
			ret += "CCC";
			break;
		case 2:
			ret += "CC";
			break;
		case 1:
			ret += "C";
			break;
		}

		switch (n_10)
		{
		case 9:
			ret += "XC";
			break;
		case 8:
			ret += "LXXX";
			break;
		case 7:
			ret += "LXX";
			break;
		case 6:
			ret += "LX";
			break;
		case 5:
			ret += "L";
			break;
		case 4:
			ret += "XL";
			break;
		case 3:
			ret += "XXX";
			break;
		case 2:
			ret += "XX";
			break;
		case 1:
			ret += "X";
			break;
		}

		switch (n_1)
		{
		case 9:
			ret += "IX";
			break;
		case 8:
			ret += "VIII";
			break;
		case 7:
			ret += "VII";
			break;
		case 6:
			ret += "VI";
			break;
		case 5:
			ret += "V";
			break;
		case 4:
			ret += "IV";
			break;
		case 3:
			ret += "III";
			break;
		case 2:
			ret += "II";
			break;
		case 1:
			ret += "I";
			break;
		}

		return ret;
	}
};

int main()
{
	Solution solution;


	while (getchar());

	return 0;
}