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
	int maxDepth(TreeNode* root)
	{
		if (root == NULL) return 0;

		int left = maxDepth(root->left);
		int right = maxDepth(root->right);

		return (left > right ? left : right) + 1;
	}
};

int main()
{
	Solution solution;


	return 0;
}