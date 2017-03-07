#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>

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
	int maxPathSum(TreeNode* root)
	{
		int ret = INT_MIN;
        search(root, ret);
        return ret;
	}

	int search(TreeNode* node, int& ret)
	{
		if (!node) return 0;

		int l = max(search(node->left, ret), 0);
		int r = max(search(node->right, ret), 0);

		ret = max(ret, l + node->val + r);

		return max(l + node->val, node->val + r);
	}
};

int main()
{
	while (getchar());

	return 0;
}