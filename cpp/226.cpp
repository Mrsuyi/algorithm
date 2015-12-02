#include <iostream>
#include <vector>
#include <queue>
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
	TreeNode* invertTree(TreeNode* root)
	{
		if (root == NULL) return NULL;

		invertTree(root->left);
		invertTree(root->right);

		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
	}
};

int main()
{
	Solution solution;


	while (getchar());

	return 0;
}