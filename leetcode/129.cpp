#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

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
	int sumNumbers(TreeNode* root)
	{
		return sum(root, 0);
	}

	int sum(TreeNode* node, int pre)
	{
		if (!node) return 0;
		if (!node->left && !node->right) return 10 * pre + node->val;
		return sum(node->left, 10 * pre + node->val) + sum(node->right, 10 * pre + node->val);
	}
};


int main()
{
	Solution solution;

	while (getchar());

	return 0;
}