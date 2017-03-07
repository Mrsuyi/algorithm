#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<int> in(numCourses, 0);
		vector<vector<int>> edge(numCourses);
		queue<int> q;

		for (auto p : prerequisites)
		{
			in[p.first]++;
			edge[p.second].push_back(p.first);
		}

		for (int i = 0; i < numCourses; i++)
		{
			if (in[i] == 0)
			{
				q.push(i);
			}
		}

		while (!q.empty())
		{
			int v = q.front();
			q.pop();

			for (int u : edge[v])
			{
				if (--in[u] == 0)
				{
					q.push(u);
				}
			}
		}

		for (int v : in)
		{
			if (v != 0)
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	while (getchar());

	return 0;
}