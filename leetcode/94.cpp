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
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> ret;

		traverse(root, ret);

		return ret;
	}

	void traverse(TreeNode* node, vector<int>& ret)
	{
		if (!node) return;
		traverse(node->left, ret);
		ret.push_back(node->val);
		traverse(node->right, ret);
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}