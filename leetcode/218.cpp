#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <functional>

using namespace std;

class Solution
{
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
	{
		vector<pair<int, int>> ret;
		// pair[0] : height   pair[1] : right
		priority_queue<pair<int, int>> hs;

		int idx = 0;
		int len = buildings.size();

		while (idx < len || !hs.empty())
		{
			int x = hs.empty() ? buildings[idx][0] :
				    idx == len ? hs.top().second : 
				    min(buildings[idx][0], hs.top().second);

			while (!hs.empty() && hs.top().second <= x) { hs.pop(); }

			while (idx < len && buildings[idx][0] == x)
			{
				hs.push(make_pair(buildings[idx][2], buildings[idx][1]));
				idx++;
			}

			int h = hs.empty() ? 0 : hs.top().first;

			if (ret.empty() || h != ret.back().second)
			{
				ret.push_back(make_pair(x, h));
			}
		}

		return ret;
	}
};

int main()
{
	Solution so;
	vector<vector<int>> input = { {2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8} };
	so.getSkyline(input);

	while (getchar());

	return 0;
}