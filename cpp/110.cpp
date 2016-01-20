#include <iostream>
#include <vector>
#include <string>
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
	bool isBalanced(TreeNode* root)
	{
		return balanced(root) != -1;
	}

	int balanced(TreeNode* root)
	{
		if (!root) return 0;

		int l = balanced(root->left);
		int r = balanced(root->right);
		
		if (l == -1 || r == -1 || abs(l - r) > 1) return -1;

		return max(l, r) + 1;
	}
};

int main()
{
	Solution solution;


	return 0;
}