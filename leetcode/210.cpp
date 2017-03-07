#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<int> ret;
		vector<vector<int>> conn(numCourses);
		vector<int> in(numCourses);
		queue<int> bfs;

		// init
		for (auto p : prerequisites)
		{
			conn[p.second].push_back(p.first);
			in[p.first]++;
		}

		// start
		for (int i = 0; i < numCourses; i++)
		{
			if (in[i] == 0) bfs.push(i);
		}

		// bfs
		ret.reserve(numCourses);
		while (!bfs.empty())
		{
			int i = bfs.front();
			bfs.pop();
			ret.push_back(i);

			for (int n : conn[i])
			{
				if (--in[n] == 0) bfs.push(n);
			}
		}

		return ret.size() == numCourses ? ret : vector<int>(0);
	}
};

int main()
{
	while (getchar());

	return 0;
}