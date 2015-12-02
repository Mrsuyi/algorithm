#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	bool isPowerOfTwo(int n)
	{
		return !(n & (n - 1)) && (n << 1);
	}
};

int main()
{
	Solution solution;

	int input;
	while (cin >> input)
	{
		cout << solution.isPowerOfTwo(input) << endl;
	}

	while (getchar());

	return 0;
}