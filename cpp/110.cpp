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
	bool balance = true;

	bool isBalanced(TreeNode* root)
	{
		if (root == NULL) return true;

		balance = true;
		depth(root);

		return balance;
	}

	int depth(TreeNode* node)
	{
		if (node == NULL) return 0;

		int left = depth(node->left);
		if (!balance) return 0;

		int right = depth(node->right);
		if (!balance) return 0;

		if (left - right > 1 || right - left > 1)
		{
			balance = false;
			return 0;
		}

		int depth = (left > right ? left : right) + 1;

		return depth;
	}
};

int main()
{
	Solution solution;


	return 0;
}