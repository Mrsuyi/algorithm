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
public:
	int hIndex(vector<int>& citations)
	{
		int len = citations.size();
		sort(citations.begin(), citations.end(), [](const int& a, const int& b)->bool { return a > b; });

		int i = 0;
		while (i < len && citations[i] >= i + 1) { i++; }

		return i;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}