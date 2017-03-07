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
	vector<TreeNode*> generateTrees(int n)
	{
		if (n == 0) return {};
		return generate(1, n);
	}

	vector<TreeNode*> generate(int l, int r)
	{
		if (l > r) return { NULL };
		if (l == r) return { new TreeNode(l) };

		vector<TreeNode*> ret;
		for (int i = l; i <= r; i++)
		{
			for (auto n_l : generate(l, i - 1))
			for (auto n_r : generate(i + 1, r))
			{
				TreeNode* root = new TreeNode(i);
				root->left = n_l;
				root->right = n_r;
				ret.push_back(root);
			}
		}
		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}