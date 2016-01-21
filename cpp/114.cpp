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
	void flatten(TreeNode* root)
	{
		build(root);
	}

	TreeNode* build(TreeNode* node)
	{
		if (!node) return NULL;

		TreeNode* l = build(node->left);
		TreeNode* r = build(node->right);

		if (l)
		{
			TreeNode* tmp = node->right;
			node->right = node->left;
			node->left = NULL;
			l->right = tmp;
		}
		return r ? r : l ? l : node;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}