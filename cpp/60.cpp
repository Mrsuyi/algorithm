#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
private:
	int factorial[9] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320 };

public:
	string getPermutation(int n, int k)
	{
		string ret;
		unsigned chosen = 0;

		for (int i = 1; i <= n; i++)
		{
			chosen |= 1 << i;
		}

		search(ret, chosen, n, k - 1);

		return ret;
	}

	void search(string& prefix, unsigned chosen, int n, int k)
	{
		if (n == 1)
		{
			int i = 1;
			while (!(chosen & (1 << i))) { i++; }
			prefix += '0' + i;
			return;
		}

		int index = k / factorial[n - 1];
		int i = 0, j = index;
		do
		{
			i++;
			while (!(chosen & (1 << i))) { i++; }
		}
		while (j-- > 0);

		prefix += '0' + i;
		chosen &= ~(1 << i);
		search(prefix, chosen, n - 1, k - index * factorial[n - 1]);
	}
};

int main()
{
	Solution solution;

	cout << solution.getPermutation(3, 2) << endl;

	while (getchar());

	return 0;
}