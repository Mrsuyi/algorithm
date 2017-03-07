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
		int l = 0, r = len - 1, mid;
		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);

			if (citations[mid] >= len - mid)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		return len - l;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}