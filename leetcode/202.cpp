#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	bool isHappy(int n)
	{
		unordered_map<int, bool> exist;

		do
		{
			exist[n] = true;

			int add = 0;

			while (n != 0)
			{
				add += (n % 10) * (n % 10);
				n /= 10;
			}

			if (add == 1)
			{
				return true;
			}

			n = add;
		}
		while (!exist[n]);

		return false;
	}
};

int main()
{
	Solution solution;


	while (getchar());

	return 0;
}