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
	bool hasPathSum(TreeNode* root, int sum)
	{
		if (root == NULL) return false;

		if ((root->left == NULL) && (root->right == NULL) && (root->val == sum))
		{
			return true;
		}

		int rest = sum - root->val;

		return hasPathSum(root->left, rest) || hasPathSum(root->right, rest);
	}
};

int main()
{
	Solution solution;

	return 0;
}