#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum)
	{
		vector<vector<int>> ret;
		vector<int> prefix;

		dfs(ret, prefix, root, sum);

		return ret;
	}

	void dfs(vector<vector<int>>& ret, vector<int>& prefix, TreeNode* node, int sum)
	{
		if (!node) return;

		if (!node->left && !node->right && node->val == sum)
		{
			vector<int> v = vector<int>(prefix);
			v.push_back(sum);
			ret.push_back(v);
			return;
		}

		prefix.push_back(node->val);
		dfs(ret, prefix, node->left, sum - node->val);
		dfs(ret, prefix, node->right, sum - node->val);
		prefix.pop_back();
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}