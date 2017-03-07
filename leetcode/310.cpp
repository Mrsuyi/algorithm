#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
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
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
	{
		if (n == 1) return { 0 };

		vector<int> in(n, 0);
		vector<vector<int>> conn(n, vector<int>(0));

		for (auto e : edges)
		{
			conn[e.first].push_back(e.second);
			conn[e.second].push_back(e.first);
			in[e.first]++;
			in[e.second]++;
		}

		queue<int> q;
		for (int i = 0; i < n; i++)
		{
			if (in[i] == 1)
			{
				q.push(i);
			}
		}

		while (n > 2)
		{
			int cnt = q.size();
			for (int i = 0; i < cnt; i++)
			{
				int v = q.front();
				q.pop();
				n--;

				for (auto k : conn[v])
				{
					in[k]--;
					if (in[k] == 1)
					{
						q.push(k);
					}
				}
			}
		}

		vector<int> ret;
		while (!q.empty())
		{
			ret.push_back(q.front());
			q.pop();
		}
		return ret;
	}
};

int main()
{
	while (getchar());

	return 0;
}