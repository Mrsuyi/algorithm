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

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}