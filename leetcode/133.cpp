#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

// DFS
class Solution
{
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		if (!node) return NULL;

		unordered_map<int, UndirectedGraphNode*> map;

		dfs(map, node);

		return map[node->label];
	}

	void dfs(unordered_map<int, UndirectedGraphNode*>& map, UndirectedGraphNode* node)
	{
		UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
		map[copy->label] = copy;

		for (auto n : node->neighbors)
		{
			if (!map[n->label])
			{
				dfs(map, n);
			}
			copy->neighbors.push_back(map[n->label]);
		}
	}
};

// BFS
class Solution
{
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		if (!node) return nullptr;

		unordered_map<int, UndirectedGraphNode*> map;
		queue<UndirectedGraphNode*> q;

		map[node->label] = new UndirectedGraphNode(node->label);
		q.push(node);
		
		while (!q.empty())
		{
			UndirectedGraphNode* node = q.front();
			q.pop();
			
			for (auto n : node->neighbors)
			{
				if (map.find(n->label) == map.end())
				{
					map[n->label] = new UndirectedGraphNode(n->label);
					q.push(n);
				}
				map[node->label]->neighbors.push_back(map[n->label]);
			}
		}
		return map[node->label];
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}