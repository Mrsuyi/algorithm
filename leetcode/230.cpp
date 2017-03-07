#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>

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
	int kthSmallest(TreeNode* root, int k)
	{
		stack<TreeNode*> stk;

		// get min
		TreeNode* node = root;
		while (node->left)
		{
			stk.push(node);
			node = node->left;
		}

		// find kth
		while (--k)
		{
			if (node->right)
			{
				node = node->right;
				while (node->left)
				{
					stk.push(node);
					node = node->left;
				}
			}
			else
			{
				node = stk.top();
				stk.pop();
			}
		}

		return node->val;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}