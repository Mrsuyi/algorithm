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
	bool Symmetric(TreeNode* left, TreeNode* right)
	{
		if (left == NULL)
		{
			return right == NULL;
		}
		else
		{
			if (right == NULL)
			{
				return false;
			}
			else
			{
				return left->val == right->val
					&& Symmetric(left->left, right->right)
					&& Symmetric(left->right, right->left);
			}
		}
	}

	bool isSymmetric(TreeNode* root)
	{
		return root == NULL ? true : Symmetric(root->left, root->right);
	}
};

int main()
{
	Solution solution;


	return 0;
}