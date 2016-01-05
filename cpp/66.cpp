#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		reverse(digits.begin(), digits.end());

		bool c = true;
		for (int i = 0; i < digits.size(); i++)
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else
			{
				digits[i]++;
				c = false;
				break;
			}
		}
		if (c) digits.push_back(1);

		reverse(digits.begin(), digits.end());
		return digits;
	}
};

int main()
{
	while (getchar());

	return 0;
}