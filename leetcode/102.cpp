#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		if (root == NULL) return {};

		int d = depth(root);

		vector<vector<int>> ret(d);

		dfs(ret, root, 0);

		return ret;
	}

	void dfs(vector<vector<int>>& ret, TreeNode* node, int level)
	{
		if (node == NULL) return;

		ret[level].push_back(node->val);
		dfs(ret, node->left, level + 1);
		dfs(ret, node->right, level + 1);
	}

	int depth(TreeNode* node)
	{
		if (node == NULL) return 0;
		
		int left = depth(node->left);
		int right = depth(node->right);

		return (left > right ? left : right) + 1;
	}
};

int main()
{
	Solution solution;


	return 0;
}