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

	//
	// dfs
	//
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		// init
		vector<vector<int>> conn = vector<vector<int>>(numCourses, vector<int>());
		vector<bool> checked = vector<bool>(numCourses, false);
		vector<bool> path = vector<bool>(numCourses, false);

		for (auto p : prerequisites) conn[p.first].push_back(p.second);
		 
		// dfs
		for (int i = 0; i < numCourses; i++)
		{
			if (!checked[i] && circle(conn, checked, path, i, numCourses)) return false;
		}

		return true;
	}

	bool circle(vector<vector<int>>& conn, vector<bool>& checked, vector<bool>& path, int pt, int n)
	{
		for (int pt2 : conn[pt])
		{
			if (path[pt2]) return true;
			
			if (!checked[pt2])
			{
				path[pt2] = true;
				if (circle(conn, checked, path, pt2, n)) return true;
				path[pt2] = false;
				checked[pt2] = true;
			}
		}
		return false;
	}
	
	//
	// bfs
	//
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<int> indegree(numCourses, 0);
		vector<vector<int>> conn(numCourses, vector<int>(0));
		queue<int> bfs;

		// init
		for (auto p : prerequisites)
		{
			conn[p.first].push_back(p.second);
			indegree[p.second]++;
		}

		// start
		for (int i = 0; i < numCourses; i++)
		{
			if (indegree[i] == 0) bfs.push(i);
		}

		// search
		while (!bfs.empty())
		{
			int root = bfs.front();
			bfs.pop();

			for (int node : conn[root])
			{
				if (--indegree[node] == 0) bfs.push(node);
			}
		}

		// conclude
		for (int i : indegree)
		{
			if (i) return false;
		}
		return true;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}