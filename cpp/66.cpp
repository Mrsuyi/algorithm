#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		auto i = digits.end() - 1;

		while (i != digits.begin() && *i == 9)
		{
			*i = 0;
			i--;
		}

		if (i == digits.begin() && *i == 9)
		{
			*i = 0;

			vector<int> ret(digits.size() + 1, 0);

			ret[0] = 1;
			copy(digits.begin(), digits.end(), ret.begin() + 1);
			
			return ret;
		}
		else
		{
			(*i)++;
			return digits;
		}
	}
};

int main()
{
	Solution solution;

	int len;
	vector<int> input;

	cin >> len;
	while (len--)
	{
		int digit;
		cin >> digit;
		input.push_back(digit);
	}
	
	vector<int> output = solution.plusOne(input);

	for (auto i = output.begin(); i != output.end(); i++)
	{
		cout << *i;
	}

	while (getchar());

	return 0;
}