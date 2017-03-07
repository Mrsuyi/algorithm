#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

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
	vector<string> ret;

	vector<string> binaryTreePaths(TreeNode* root)
	{
		if (!root) return{};

		ret.clear();

		dfs(root, to_string(root->val));

		return ret;
	}

	void dfs(TreeNode* node, string path)
	{
		if (!node->left && !node->right)
		{
			ret.push_back(path);
			return;
		}

		if (node->left)
		{
			dfs(node->left, path + "->" + to_string(node->left->val));
		}
		if (node->right)
		{
			dfs(node->right, path + "->" + to_string(node->right->val));
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}