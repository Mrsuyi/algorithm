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
	void flatten(TreeNode* root)
	{
		f(root);
	}

	TreeNode* f(TreeNode* node)
	{
		if (!node) return NULL;

		TreeNode* tmp;
		TreeNode* l_tail = f(node->left);
		TreeNode* r_tail = f(node->right);

		if (l_tail && r_tail)
		{
			TreeNode* tmp = node->right;
			node->right = node->left;
			node->left = NULL;
			l_tail->right = tmp;
			return r_tail;
		}
		else if (l_tail)
		{
			node->right = node->left;
			node->left = NULL;
			return l_tail;
		}
		else if (r_tail)
		{
			return r_tail;
		}
		else
		{
			return node;
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}