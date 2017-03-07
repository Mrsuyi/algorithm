#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	bool canWinNim(int n)
	{
		return n % 4 != 0;
	}
};

int main()
{
	Solution solution;

	cout << solution.canWinNim(9) << endl;

	while (getchar());

	return 0;
}