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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (!root || root == p || root == q) return root;

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		return left ? (right ? root : left) : (right ? right : NULL);
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}