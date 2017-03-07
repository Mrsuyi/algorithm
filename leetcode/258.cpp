#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int addDigits(int num)
	{
		return num ? (num % 9 ? (num % 9) : 9) : 0;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}